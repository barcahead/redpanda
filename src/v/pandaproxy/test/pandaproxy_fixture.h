#pragma once

#include "config/configuration.h"
#include "http/client.h"
#include "kafka/requests/metadata_request.h"
#include "pandaproxy/application.h"
#include "pandaproxy/client/client.h"
#include "pandaproxy/configuration.h"
#include "pandaproxy/proxy.h"
#include "redpanda/tests/fixture.h"

class pandaproxy_test_fixture : public redpanda_thread_fixture {
public:
    pandaproxy_test_fixture()
      : redpanda_thread_fixture()
      , proxy() {
        configure_proxy();
        start_proxy();
    }

    pandaproxy_test_fixture(pandaproxy_test_fixture const&) = delete;
    pandaproxy_test_fixture(pandaproxy_test_fixture&&) = delete;
    pandaproxy_test_fixture operator=(pandaproxy_test_fixture const&) = delete;
    pandaproxy_test_fixture operator=(pandaproxy_test_fixture&&) = delete;

    ~pandaproxy_test_fixture() { proxy.shutdown(); }

    http::client make_client() {
        rpc::base_transport::configuration transport_cfg;
        transport_cfg.server_addr
          = pandaproxy::shard_local_cfg().pandaproxy_api().resolve().get();
        return http::client(transport_cfg);
    }

private:
    void configure_proxy() {
        pandaproxy::shard_local_cfg().developer_mode.set_value(true);
        pandaproxy::client::shard_local_cfg().brokers.set_value(
          std::vector<unresolved_address>{
            config::shard_local_cfg().advertised_kafka_api()});
    }

    void start_proxy() {
        proxy.initialize();
        proxy.check_environment();
        proxy.configure_admin_server();
        proxy.wire_up_services();
        proxy.start();
    }

    pandaproxy::application proxy;
};
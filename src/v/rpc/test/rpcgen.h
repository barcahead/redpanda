
// This file is autogenerated. Manual changes will be lost.
#pragma once

#include "rpc/client.h"
#include "rpc/netbuf.h"
#include "rpc/parse_utils.h"
#include "rpc/service.h"
#include "rpc/types.h"
#include "seastarx.h"

// extra includes
#include "rpc/test/rpc_gen_types.h"

#include <seastar/core/reactor.hh>
#include <seastar/core/scheduling.hh>

#include <functional>
#include <tuple>

namespace cycling {

class team_movistar_service : public rpc::service {
public:
    class client;

    team_movistar_service(scheduling_group sc, smp_service_group ssg)
      : _sc(sc)
      , _ssg(ssg) {
    }

    team_movistar_service(team_movistar_service&& o) noexcept
      : _sc(std::move(o._sc))
      , _ssg(std::move(o._ssg))
      , _methods(std::move(o._methods)) {
    }

    team_movistar_service& operator=(team_movistar_service&& o) noexcept {
        if (this != &o) {
            this->~team_movistar_service();
            new (this) team_movistar_service(std::move(o));
        }
        return *this;
    }

    virtual ~team_movistar_service() noexcept = default;

    scheduling_group& get_scheduling_group() override {
        return _sc;
    }

    smp_service_group& get_smp_service_group() override {
        return _ssg;
    }

    rpc::method* method_from_id(uint32_t idx) final {
        switch (idx) {
        case 3887553648:
            return &_methods[0];
        case 3924709550:
            return &_methods[1];
        default:
            return nullptr;
        }
    }
    /// \brief ultimate_cf_slx -> nairo_quintana
    virtual future<rpc::netbuf>
    raw_canyon(input_stream<char>& in, rpc::streaming_context& ctx) {
        auto fapply = execution_helper<ultimate_cf_slx, nairo_quintana>();
        return fapply.exec(
          in,
          ctx,
          3887553648,
          [this](ultimate_cf_slx&& t, rpc::streaming_context& ctx)
            -> future<nairo_quintana> { return canyon(std::move(t), ctx); });
    }
    virtual future<nairo_quintana>
    canyon(ultimate_cf_slx&&, rpc::streaming_context&) {
        throw std::runtime_error("unimplemented method");
    }
    /// \brief san_francisco -> mount_tamalpais
    virtual future<rpc::netbuf>
    raw_ibis_hakka(input_stream<char>& in, rpc::streaming_context& ctx) {
        auto fapply = execution_helper<san_francisco, mount_tamalpais>();
        return fapply.exec(
          in,
          ctx,
          3924709550,
          [this](san_francisco&& t, rpc::streaming_context& ctx)
            -> future<mount_tamalpais> {
              return ibis_hakka(std::move(t), ctx);
          });
    }
    virtual future<mount_tamalpais>
    ibis_hakka(san_francisco&&, rpc::streaming_context&) {
        throw std::runtime_error("unimplemented method");
    }

private:
    scheduling_group _sc;
    smp_service_group _ssg;
    std::array<rpc::method, 2> _methods{
      {rpc::method([this](input_stream<char>& in, rpc::streaming_context& ctx) {
           return raw_canyon(in, ctx);
       }),
       rpc::method([this](input_stream<char>& in, rpc::streaming_context& ctx) {
           return raw_ibis_hakka(in, ctx);
       })}};
};
class team_movistar_service::client : public rpc::client {
public:
    client(rpc::client_configuration c)
      : rpc::client(std::move(c), "team_movistar") {
    }
    virtual inline future<rpc::client_context<nairo_quintana>>
    canyon(ultimate_cf_slx&& r) {
        return send_typed<ultimate_cf_slx, nairo_quintana>(
          std::move(r), 3887553648);
    }
    virtual inline future<rpc::client_context<mount_tamalpais>>
    ibis_hakka(san_francisco&& r) {
        return send_typed<san_francisco, mount_tamalpais>(
          std::move(r), 3924709550);
    }
};

} // namespace cycling

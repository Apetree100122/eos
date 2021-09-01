#pragma once
#include <appbase/application.hpp>
#include <appbase/plugin.hpp>
#include <boost/signals2/connection.hpp>
#include <optional>

namespace eosio {

class amqp_trace_plugin : public appbase::plugin<amqp_trace_plugin> {

 public:
   APPBASE_PLUGIN_REQUIRES()

   amqp_trace_plugin();
   virtual ~amqp_trace_plugin();

   virtual void set_program_options(appbase::options_description& cli, appbase::options_description& cfg) override;
   void plugin_initialize(const appbase::variables_map& options);
   void plugin_startup();
   void plugin_shutdown();
   void handle_sighup() override;

 private:
   std::shared_ptr<struct amqp_trace_plugin_impl> my;
   std::optional<boost::signals2::scoped_connection> applied_transaction_connection;
};

} // namespace eosio
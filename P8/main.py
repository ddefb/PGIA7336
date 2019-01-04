import sys

sys.path.insert(0, './database')

import rules_repository as rrep
import actions_repository as arep
import events_repository as erep

rules = rrep.RulesRepository("postgres", "osboxes.org", "localhost", "teste")
actions = arep.ActionsRepository("postgres", "osboxes.org", "localhost", "teste")
events = erep.EventsRepository("postgres", "osboxes.org", "localhost", "teste")

# rules.insert_rule("t_var >= 50 or t_var >= 55")
# rules.insert_rule("t_var < 30")

# actions.insert_action("bomb_device & valve_device")
# actions.insert_action("not bomb_device & not valve_device")

# events.insert_event(30, 6)
# events.insert_event(29, 7)

# rules.delete_rule(17)
# actions.delete_action(17)
# events.delete_event(17)

# for i in range(100):
# 	events.delete_event(i)

# for i in range(100):
# 	rules.delete_rule(i)

# for i in range(100):
# 	actions.delete_action(i)
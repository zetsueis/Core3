pol_revver = Creature:new {
  objectName = "",
  socialGroup = "rebel",
  pvpFaction = "rebel",
  faction = "rebel",
  level = 21,
  chanceHit = 0.34,
  damageMin = 200,
  damageMax = 210,
  baseXp = 2006,
  baseHAM = 5400,
  baseHAMmax = 6600,
  armor = 0,
  resists = {10,10,10,10,10,10,10,-1,-1},
  meatType = "",
  meatAmount = 0,
  hideType = "",
  hideAmount = 0,
  boneType = "",
  boneAmount = 0,
  milk = 0,
  tamingChance = 0,
  ferocity = 0,
  pvpBitmask = ATTACKABLE,
  creatureBitmask = NONE,
  optionsBitmask = 136,
  diet = HERBIVORE,

  templates = {
    "object/mobile/dressed_rebel_army_captain_trandoshan_female.iff",
  },
  lootGroups = { },
  weapons = {"rebel_weapons_medium"},
  conversationTemplate = "boss_nass_mission_target_convotemplate",
  attacks = merge(riflemanmaster,pistoleermaster,carbineermaster,brawlermaster)
}

CreatureTemplates:addCreatureTemplate(pol_revver, "pol_revver")

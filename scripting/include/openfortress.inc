#if defined _openfortress_included
	#endinput
#endif
#define _openfortress_included

#if defined _tf2_included
	#error You cannot have both TF2 and OpenFortress includes included in your plugin
#endif

// We're overriding this shit
// The colon ":" after the enums untags them, so there aren't stupid fucking tag mismatches on literally everything

#define TF_STUNFLAG_SLOWDOWN        (1 << 0)    /**< activates slowdown modifier */
#define TF_STUNFLAG_BONKSTUCK       (1 << 1)    /**< bonk sound, stuck */
#define TF_STUNFLAG_LIMITMOVEMENT   (1 << 2)    /**< disable forward/backward movement */
#define TF_STUNFLAG_CHEERSOUND      (1 << 3)    /**< cheering sound */
#define TF_STUNFLAG_NOSOUNDOREFFECT (1 << 5)    /**< no sound or particle */
#define TF_STUNFLAG_THIRDPERSON     (1 << 6)    /**< panic animation */
#define TF_STUNFLAG_GHOSTEFFECT     (1 << 7)    /**< ghost particles */
#define TF_STUNFLAG_SOUND           (1 << 8)    /**< sound */

#define TF_STUNFLAGS_LOSERSTATE     TF_STUNFLAG_SLOWDOWN|TF_STUNFLAG_NOSOUNDOREFFECT|TF_STUNFLAG_THIRDPERSON
#define TF_STUNFLAGS_GHOSTSCARE     TF_STUNFLAG_GHOSTEFFECT|TF_STUNFLAG_THIRDPERSON
#define TF_STUNFLAGS_SMALLBONK      TF_STUNFLAG_THIRDPERSON|TF_STUNFLAG_SLOWDOWN
#define TF_STUNFLAGS_NORMALBONK     TF_STUNFLAG_BONKSTUCK
#define TF_STUNFLAGS_BIGBONK        TF_STUNFLAG_CHEERSOUND|TF_STUNFLAG_BONKSTUCK

enum TFClassType
{
	TFClass_Unknown = 0,
	TFClass_Scout,
	TFClass_Sniper,
	TFClass_Soldier,
	TFClass_DemoMan,
	TFClass_Medic,
	TFClass_Heavy,
	TFClass_Pyro,
	TFClass_Spy,
	TFClass_Engineer,
	TFClass_Mercenary,
	TFClass_Civilian,		// TF_LAST_NORMAL_CLASS
	TFClass_Juggernaut,
	TFClass_CountAll,

	TFClass_Random
};

enum TFTeam
{
	TFTeam_Unassigned = 0,
	TFTeam_Spectator = 1,
	TFTeam_Red = 2,
	TFTeam_Blue = 3,
	TFTeam_Mercenary,
	TFTeam_NPC,

	TFTeam_COUNT,
};

enum TFCond
{
	TFCond_Slowed = 0, //0: Revving Minigun, Sniper Rifle. Gives zoomed/revved pose
	TFCond_Zoomed, //1: Sniper Rifle zooming
	TFCond_Disguising, //2: Disguise smoke
	TFCond_Disguised, //3: Disguise
	TFCond_Cloaked, //4: Cloak effect
	TFCond_Ubercharged, //5: Invulnerability, removed when being healed or by another Uber effect
	TFCond_TeleportedGlow, //6: Teleport trail effect
	TFCond_Taunting, //7: Used for taunting, can remove to stop taunting
	TFCond_UberchargeFading, //8: Invulnerability expiration effect
	TFCond_Unknown1, //9
	TFCond_CloakFlicker = 9, //9: Cloak flickering effect
	TFCond_Teleporting, //10: Used for teleporting, does nothing applying
	TFCond_Kritzkrieged, //11: Crit boost, removed when being healed or another Uber effect
	TFCond_Unknown2, //12
	TFCond_TmpDamageBonus = 12, //12: Temporary damage buff, something along with attribute 19
	TFCond_DeadRingered, //13: Dead Ringer damage resistance, gives TFCond_Cloaked
	TFCond_Bonked, //14: Bonk! Atomic Punch effect
	TFCond_Dazed, //15: Slow effect, can remove to remove stun effects
	TFCond_Buffed, //16: Buff Banner mini-crits, icon, and glow
	TFCond_Charging, //17: Forced forward, charge effect
	TFCond_DemoBuff, //18: Eyelander eye glow
	TFCond_CritCola, //19: Mini-crit effect
	TFCond_InHealRadius, //20: Ring effect, rings disappear after a taunt ends
	TFCond_Healing, //21: Used for healing, does nothing applying
	TFCond_OnFire, //22: Ignite sound and vocals, can remove to remove afterburn
	TFCond_Overhealed, //23: Used for overheal, does nothing applying
	TFCond_Jarated, //24: Jarate effect
	TFCond_Bleeding, //25: Bleed effect
	TFCond_DefenseBuffed, //26: Battalion's Backup's defense, icon, and glow
	TFCond_Milked, //27: Mad Milk effect
	TFCond_MegaHeal, //28: Quick-Fix Ubercharge's knockback/stun immunity and visual effect
	TFCond_RegenBuffed, //29: Concheror's speed boost, heal on hit, icon, and glow
	TFCond_MarkedForDeath, //30: Fan o' War marked-for-death effect
	TFCond_NoHealingDamageBuff, //31: Mini-crits, blocks healing, glow, no weapon mini-crit effects
	TFCond_SpeedBuffAlly, //32: Disciplinary Action speed boost
	TFCond_HalloweenCritCandy, //33: Halloween pumpkin crit-boost
	TFCond_CritCanteen, //34: Crit-boost and doubles Sentry Gun fire-rate
	TFCond_CritDemoCharge, //35: Crit glow, adds TFCond_Charging when charge meter is below 75%
	TFCond_CritHype, //36: Soda Popper multi-jump effect
	TFCond_CritOnFirstBlood, //37: Arena first blood crit-boost
	TFCond_CritOnWin, //38: End-of-round crit-boost (May not remove correctly?)
	TFCond_CritOnFlagCapture, //39: Intelligence capture crit-boost
	TFCond_CritOnKill, //40: Crit-boost from crit-on-kill weapons
	TFCond_RestrictToMelee, //41: Prevents switching once melee is out
	TFCond_DefenseBuffNoCritBlock, //42: MvM Bomb Carrier defense buff (TFCond_DefenseBuffed without crit resistance)
	TFCond_Reprogrammed, //43: No longer functions
	TFCond_CritMmmph, //44: Phlogistinator crit-boost
	TFCond_DefenseBuffMmmph, //45: Old Phlogistinator defense buff
	TFCond_FocusBuff, //46: Hitman's Heatmaker no-unscope and faster Sniper charge
	TFCond_DisguiseRemoved, //47: Enforcer damage bonus removed
	TFCond_MarkedForDeathSilent, //48: Marked-for-death without sound effect
	TFCond_DisguisedAsDispenser, //49: Dispenser disguise when crouching, max movement speed, sentries ignore player
	TFCond_Sapped, //50: Sapper sparkle effect in MvM
	TFCond_UberchargedHidden, //51: Out-of-bounds robot invulnerability effect
	TFCond_UberchargedCanteen, //52: Invulnerability effect and Sentry Gun damage resistance
	TFCond_HalloweenBombHead, //53: Bomb head effect (does not explode)
	TFCond_HalloweenThriller, //54: Forced Thriller taunting
	TFCond_RadiusHealOnDamage, //55: Radius healing, adds TFCond_InHealRadius, TFCond_Healing. Removed when a taunt ends, but this condition stays but does nothing
	TFCond_CritOnDamage, //56: Miscellaneous crit-boost
	TFCond_UberchargedOnTakeDamage, //57: Miscellaneous invulnerability
	TFCond_UberBulletResist, //58: Vaccinator Uber bullet resistance
	TFCond_UberBlastResist, //59: Vaccinator Uber blast resistance
	TFCond_UberFireResist, //60: Vaccinator Uber fire resistance
	TFCond_SmallBulletResist, //61: Vaccinator healing bullet resistance
	TFCond_SmallBlastResist, //62: Vaccinator healing blast resistance
	TFCond_SmallFireResist, //63: Vaccinator healing fire resistance
	TFCond_Stealthed, //64: Cloaked until next attack
	TFCond_MedigunDebuff, //65: Unknown
	TFCond_StealthedUserBuffFade, //66: Cloaked, will appear for a few seconds on attack and cloak again
	TFCond_BulletImmune, //67: Full bullet immunity
	TFCond_BlastImmune, //68: Full blast immunity
	TFCond_FireImmune, //69: Full fire immunity
	TFCond_PreventDeath, //70: Survive to 1 health, then the condition is removed
	TFCond_MVMBotRadiowave, //71: Stuns bots and applies radio effect
	TFCond_HalloweenSpeedBoost, //72: Speed boost, non-melee fire rate and reload, infinite air jumps
	TFCond_HalloweenQuickHeal, //73: Healing effect, adds TFCond_Healing along with TFCond_MegaHeal temporarily
	TFCond_HalloweenGiant, //74: Double size, x10 max health increase, ammo regeneration, and forced thirdperson
	TFCond_HalloweenTiny, //75: Half size and increased head size
	TFCond_HalloweenInHell, //76: Applies TFCond_HalloweenGhostMode when the player dies
	TFCond_HalloweenGhostMode, //77: Becomes a ghost unable to attack but can fly
	TFCond_MiniCritOnKill, //78: Mini-crits effect
	TFCond_DodgeChance, //79
	TFCond_ObscuredSmoke = 79, //79: 75% chance to dodge an attack
	TFCond_Parachute, //80: Parachute effect, removed when touching the ground
	TFCond_BlastJumping, //81: Player is blast jumping
	TFCond_HalloweenKart, //82: Player forced into a Halloween kart
	TFCond_HalloweenKartDash, //83: Forced forward if in TFCond_HalloweenKart, zoom in effect, and dash animations
	TFCond_BalloonHead, //84: Big head and lowered gravity
	TFCond_MeleeOnly, //85: Forced melee, along with TFCond_SpeedBuffAlly and TFCond_HalloweenTiny
	TFCond_SwimmingCurse, //86: Swim in the air with Jarate overlay
	TFCond_HalloweenKartNoTurn, //87
	TFCond_FreezeInput = 87, //87: Prevents player from using controls
	TFCond_HalloweenKartCage, //88: Puts a cage around the player if in TFCond_HalloweenKart, otherwise crashes
	TFCond_HasRune, //89: Has a powerup
	TFCond_RuneStrength, //90: Double damage and no damage falloff
	TFCond_RuneHaste, //91: Double fire rate, reload speed, clip and ammo size, and 30% faster movement speed
	TFCond_RuneRegen, //92: Regen ammo, health, and metal
	TFCond_RuneResist, //93: Takes 1/2 damage and critical immunity
	TFCond_RuneVampire, //94: Takes 3/4 damage, gain health on damage, and 40% increase in max health
	TFCond_RuneWarlock, //95: Attacker takes damage and knockback on hitting the player and 50% increase in max health
	TFCond_RunePrecision, //96: Less bullet spread, no damage falloff, 250% faster projectiles, and double damage, faster charge, and faster re-zoom for Sniper Rifles
	TFCond_RuneAgility, //97: Increased movement speed, grappling hook speed, jump height, and instant weapon switch
	TFCond_GrapplingHook, //98: Used when a player fires their grappling hook, no effect applying or removing
	TFCond_GrapplingHookSafeFall, //99: Used when a player is pulled by their grappling hook, no effect applying or removing
	TFCond_GrapplingHookLatched, //100: Used when a player latches onto a wall, no effect applying or removing
	TFCond_GrapplingHookBleeding, //101: Used when a player is hit by attacker's grappling hook
	TFCond_AfterburnImmune, //102: Deadringer afterburn immunity
	TFCond_RuneKnockout, //103: Melee and grappling hook only, increased max health, knockback immunity, x4 more damage against buildings, and knockbacks a powerup off a victim on hit
	TFCond_RuneImbalance, //104: Prevents gaining a crit-boost or Uber powerups
	TFCond_CritRuneTemp, //105: Crit-boost effect
	TFCond_PasstimeInterception, //106: Used when a player intercepts the Jack/Ball
	TFCond_SwimmingNoEffects, //107: Swimming in the air without animations or overlay
	TFCond_EyeaductUnderworld, //108: Refills max health, short Uber, escaped the underworld message on removal
	TFCond_KingRune, //109: Increased max health and applies TFCond_KingAura
	TFCond_PlagueRune, //110: Radius health kit stealing, increased max health, TFCond_Plague on touching a victim
	TFCond_SupernovaRune, //111: Charge meter passively increasing, when charged activiated causes radius Bonk stun
	TFCond_Plague, //112: Plague sound effect and message, blocks King powerup health regen
	TFCond_KingAura, //113: Increased fire rate, reload speed, and health regen to players in a radius
	TFCond_SpawnOutline, //114: Outline and health meter of teammates (and disguised spies)
	TFCond_KnockedIntoAir, //115: Used when a player is airblasted
	TFCond_CompetitiveWinner, //116: Unknown
	TFCond_CompetitiveLoser, //117: Unknown
	TFCond_NoTaunting_DEPRECATED, //118
	TFCond_HealingDebuff = 118, //118: Healing debuff from Medics and dispensers
	TFCond_PasstimePenaltyDebuff, //119: Marked-for-death effect
	TFCond_GrappledToPlayer, //120: Prevents taunting and some Grappling Hook actions
	TFCond_GrappledByPlayer, //121: Unknown
	TFCond_ParachuteDeployed, //122: Parachute deployed, prevents reopening it
	TFCond_Gas, //123: Gas Passer effect
	TFCond_BurningPyro, //124: Dragon's Fury afterburn on Pyros
	TFCond_RocketPack, //125: Thermal Thruster launched effects, prevents reusing
	TFCond_LostFooting, //126: Less ground friction
	TFCond_AirCurrent, //127: Reduced air control and friction
	TFCond_SpawnProtect, // 128
	TFCond_Berserk, // 129
	TFCond_Shield, // 130
	TFCond_CritPowerup, // 131
	TFCond_InvisPowerup, // 132
	TFCond_Haste, // 133
	TFCond_Juggernaught, // 134
	TFCond_Poison,
	TFCond_Tranq,

	TFCond_LAST
};

const float TFCondDuration_Infinite = -1.0;

enum TFObjectType
{
	TFObject_CartDispenser = 0,
	TFObject_Dispenser = 0,
	TFObject_Teleporter = 1,
	TFObject_Sentry = 2,
	TFObject_Sapper = 3
};

enum TFObjectMode
{
	TFObjectMode_None = 0,
	TFObjectMode_Entrance = 0,
	TFObjectMode_Exit = 1
};

#define TF_CONDFLAG_NONE            0
#define TF_CONDFLAG_SLOWED          (1 << 0)
#define TF_CONDFLAG_ZOOMED          (1 << 1)
#define TF_CONDFLAG_DISGUISING      (1 << 2)
#define TF_CONDFLAG_DISGUISED       (1 << 3)
#define TF_CONDFLAG_CLOAKED         (1 << 4)
#define TF_CONDFLAG_UBERCHARGED     (1 << 5)
#define TF_CONDFLAG_TELEPORTGLOW    (1 << 6)
#define TF_CONDFLAG_TAUNTING        (1 << 7)
#define TF_CONDFLAG_UBERCHARGEFADE  (1 << 8)
#define TF_CONDFLAG_CLOAKFLICKER    (1 << 9)
#define TF_CONDFLAG_TELEPORTING     (1 << 10)
#define TF_CONDFLAG_KRITZKRIEGED    (1 << 11)
#define TF_CONDFLAG_DEADRINGERED    (1 << 13)
#define TF_CONDFLAG_BONKED          (1 << 14)
#define TF_CONDFLAG_DAZED           (1 << 15)
#define TF_CONDFLAG_BUFFED          (1 << 16)
#define TF_CONDFLAG_CHARGING        (1 << 17)
#define TF_CONDFLAG_DEMOBUFF        (1 << 18)
#define TF_CONDFLAG_CRITCOLA        (1 << 19)
#define TF_CONDFLAG_INHEALRADIUS    (1 << 20)
#define TF_CONDFLAG_HEALING         (1 << 21)
#define TF_CONDFLAG_ONFIRE          (1 << 22)
#define TF_CONDFLAG_OVERHEALED      (1 << 23)
#define TF_CONDFLAG_JARATED         (1 << 24)
#define TF_CONDFLAG_BLEEDING        (1 << 25)
#define TF_CONDFLAG_DEFENSEBUFFED   (1 << 26)
#define TF_CONDFLAG_MILKED          (1 << 27)
#define TF_CONDFLAG_MEGAHEAL        (1 << 28)
#define TF_CONDFLAG_REGENBUFFED     (1 << 29)
#define TF_CONDFLAG_MARKEDFORDEATH  (1 << 30)

#define TF_DEATHFLAG_KILLERDOMINATION   (1 << 0)
#define TF_DEATHFLAG_ASSISTERDOMINATION (1 << 1)
#define TF_DEATHFLAG_KILLERREVENGE      (1 << 2)
#define TF_DEATHFLAG_ASSISTERREVENGE    (1 << 3)
#define TF_DEATHFLAG_FIRSTBLOOD         (1 << 4)
#define TF_DEATHFLAG_DEADRINGER         (1 << 5)
#define TF_DEATHFLAG_INTERRUPTED        (1 << 6)
#define TF_DEATHFLAG_GIBBED             (1 << 7)
#define TF_DEATHFLAG_PURGATORY          (1 << 8)
#define TF_DEATHFLAG_MINIBOSS           (1 << 9)
#define TF_DEATHFLAG_AUSTRALIUM         (1 << 10)

// Custom kill identifiers for the customkill property on the player_death event
enum {
	TF_CUSTOM_HEADSHOT = 1,
	TF_CUSTOM_BACKSTAB,
	TF_CUSTOM_BURNING,
	TF_CUSTOM_WRENCH_FIX,
	TF_CUSTOM_MINIGUN,
	TF_CUSTOM_SUICIDE,
	TF_CUSTOM_TAUNT_HADOUKEN,
	TF_CUSTOM_BURNING_FLARE,
	TF_CUSTOM_TAUNT_HIGH_NOON,
	TF_CUSTOM_TAUNT_GRAND_SLAM,
	TF_CUSTOM_PENETRATE_MY_TEAM,
	TF_CUSTOM_PENETRATE_ALL_PLAYERS,
	TF_CUSTOM_TAUNT_FENCING,
	TF_CUSTOM_PENETRATE_HEADSHOT,
	TF_CUSTOM_TAUNT_ARROW_STAB,
	TF_CUSTOM_TELEFRAG,
	TF_CUSTOM_BURNING_ARROW,
	TF_CUSTOM_FLYINGBURN,
	TF_CUSTOM_PUMPKIN_BOMB,
	TF_CUSTOM_DECAPITATION,
	TF_CUSTOM_TAUNT_GRENADE,
	TF_CUSTOM_BASEBALL,
	TF_CUSTOM_CHARGE_IMPACT,
	TF_CUSTOM_TAUNT_BARBARIAN_SWING,
	TF_CUSTOM_AIR_STICKY_BURST,
	TF_CUSTOM_DEFENSIVE_STICKY,
	TF_CUSTOM_PICKAXE,
	TF_CUSTOM_ROCKET_DIRECTHIT,
	TF_CUSTOM_TAUNT_UBERSLICE,
	TF_CUSTOM_PLAYER_SENTRY,
	TF_CUSTOM_STANDARD_STICKY,
	TF_CUSTOM_SHOTGUN_REVENGE_CRIT,
	TF_CUSTOM_TAUNT_ENGINEER_SMASH,
	TF_CUSTOM_BLEEDING,
	TF_CUSTOM_GOLD_WRENCH,
	TF_CUSTOM_CARRIED_BUILDING,
	TF_CUSTOM_COMBO_PUNCH,
	TF_CUSTOM_TAUNT_ENGINEER_ARM,
	TF_CUSTOM_FISH_KILL,
	TF_CUSTOM_TRIGGER_HURT,
	TF_CUSTOM_DECAPITATION_BOSS,
	TF_CUSTOM_STICKBOMB_EXPLOSION,
	TF_CUSTOM_AEGIS_ROUND,
	TF_CUSTOM_FLARE_EXPLOSION,
	TF_CUSTOM_BOOTS_STOMP,
	TF_CUSTOM_PLASMA,
	TF_CUSTOM_PLASMA_CHARGED,
	TF_CUSTOM_PLASMA_GIB,
	TF_CUSTOM_PRACTICE_STICKY,
	TF_CUSTOM_EYEBALL_ROCKET,
	TF_CUSTOM_HEADSHOT_DECAPITATION,
	TF_CUSTOM_TAUNT_ARMAGEDDON,
	TF_CUSTOM_FLARE_PELLET,
	TF_CUSTOM_CLEAVER,
	TF_CUSTOM_CLEAVER_CRIT,
	TF_CUSTOM_SAPPER_RECORDER_DEATH,
	TF_CUSTOM_MERASMUS_PLAYER_BOMB,
	TF_CUSTOM_MERASMUS_GRENADE,
	TF_CUSTOM_MERASMUS_ZAP,
	TF_CUSTOM_MERASMUS_DECAPITATION,
	TF_CUSTOM_CANNONBALL_PUSH,
	TF_CUSTOM_TAUNT_ALLCLASS_GUITAR_RIFF,
	TF_CUSTOM_THROWABLE,
	TF_CUSTOM_THROWABLE_KILL,
	TF_CUSTOM_SPELL_TELEPORT,
	TF_CUSTOM_SPELL_SKELETON,
	TF_CUSTOM_SPELL_MIRV,
	TF_CUSTOM_SPELL_METEOR,
	TF_CUSTOM_SPELL_LIGHTNING,
	TF_CUSTOM_SPELL_FIREBALL,
	TF_CUSTOM_SPELL_MONOCULUS,
	TF_CUSTOM_SPELL_BLASTJUMP,
	TF_CUSTOM_SPELL_BATS,
	TF_CUSTOM_SPELL_TINY,
	TF_CUSTOM_KART,
	TF_CUSTOM_GIANT_HAMMER,
	TF_CUSTOM_RUNE_REFLECT,
	TF_CUSTOM_DRAGONS_FURY_IGNITE,
	TF_CUSTOM_DRAGONS_FURY_BONUS_BURNING,
	TF_CUSTOM_SLAP_KILL,
	TF_CUSTOM_CROC,
	TF_CUSTOM_TAUNTATK_GASBLAST,
//	TF_CUSTOM_AXTINGUISHER_BOOSTED
	TF_CUSTOM_CRIT_POWERUP
};

// Weapon codes as used in some events, such as player_death
// (not to be confused with Item Definition Indexes)
enum {
	TF_WEAPON_NONE = 0,

	TF_WEAPON_BAT,
	TF_WEAPON_BOTTLE, 
	TF_WEAPON_FIREAXE,
	TF_WEAPON_CLUB,
	TF_WEAPON_CROWBAR,
	TF_WEAPON_KNIFE,
	TF_WEAPON_FISTS,
	TF_WEAPON_SHOVEL,
	TF_WEAPON_WRENCH,
	TF_WEAPON_BONESAW,
	TF_WEAPON_SHOTGUN,
	TF_WEAPON_SCATTERGUN,
	TF_WEAPON_SNIPERRIFLE,
	TF_WEAPON_MINIGUN,
	TF_WEAPON_SMG,
	TF_WEAPON_SYRINGEGUN_MEDIC,
	TF_WEAPON_TRANQ,
	TF_WEAPON_ROCKETLAUNCHER,
	TF_WEAPON_GRENADELAUNCHER,
	TF_WEAPON_PIPEBOMBLAUNCHER,
	TF_WEAPON_FLAMETHROWER,
	TF_WEAPON_PISTOL,
	TF_WEAPON_PISTOL_SCOUT,
	TF_WEAPON_REVOLVER,
	TF_WEAPON_NAILGUN,
	TF_WEAPON_PDA,
	TF_WEAPON_PDA_ENGINEER_BUILD,
	TF_WEAPON_PDA_ENGINEER_DESTROY,
	TF_WEAPON_PDA_SPY,
	TF_WEAPON_BUILDER,
	TF_WEAPON_MEDIGUN,
	TF_WEAPON_FLAMETHROWER_ROCKET,
	TF_WEAPON_SENTRY_BULLET,
	TF_WEAPON_SENTRY_ROCKET,
	TF_WEAPON_DISPENSER,
	TF_WEAPON_INVIS,
	TF_WEAPON_RAILGUN,
	TF_WEAPON_SUPERSHOTGUN,
	TF_WEAPON_PISTOL_MERCENARY,
	TF_WEAPON_REVOLVER_MERCENARY,
	TF_WEAPON_GATLINGGUN,
	TF_WEAPON_PISTOL_AKIMBO,
	TF_WEAPON_UMBRELLA,
	TF_WEAPON_SMG_MERCENARY,
	TF_WEAPON_TOMMYGUN,
	TF_WEAPON_GRENADELAUNCHER_MERCENARY,
	TF_WEAPON_ROCKETLAUNCHER_DM,
	TF_WEAPON_ASSAULTRIFLE,
	TF_WEAPON_C4,
	TF_WEAPON_BERSERK,
	TF_WEAPON_PHYSCANNON,
	TF_WEAPON_SUPER_ROCKETLAUNCHER,
	TF_WEAPON_CHAINSAW,
	TF_WEAPON_DYNAMITE_BUNDLE,
	TF_WEAPON_LIGHTNING_GUN,
	TF_WEAPON_GRAPPLE,
	TF_WEAPON_GIB,
	TF_WEAPON_CLAWS,
	TF_WEAPON_JUGGERNAUGHT,
	
	TFC_WEAPON_SHOTGUN_SB,
	TFC_WEAPON_SHOTGUN_DB,
	TFC_WEAPON_CROWBAR,
	TFC_WEAPON_UMBRELLA,
	TFC_WEAPON_RAILPISTOL,
	TFC_WEAPON_ASSAULTCANNON,
	TFC_WEAPON_NAILGUN,
	TFC_WEAPON_NAILGUN_SUPER,
	TFC_WEAPON_KNIFE,
	TFC_WEAPON_TRANQ,
	TFC_WEAPON_RPG,
	TFC_WEAPON_SNIPER_RIFLE,
	TFC_WEAPON_ASSAULT_RIFLE,
	TFC_WEAPON_FLAMETHROWER,
	TFC_WEAPON_INCENDIARYCANNON,
	TFC_WEAPON_MEDKIT,
	TFC_WEAPON_WRENCH,
	TFC_WEAPON_GRENADELAUNCHER,
	TFC_WEAPON_PIPEBOMBLAUNCHER,

	//NOTENOTE: Not normal throwable grenades, these are for the grenade launcher projectiles
	TF_WEAPON_GRENADE_DEMOMAN,
	TF_WEAPON_GRENADE_PIPEBOMB,
	TF_WEAPON_GRENADE_MIRV,
	TF_WEAPON_GRENADE_MIRVBOMB,

	TF_WEAPON_COUNT
};

// TF2 Weapon Loadout Slots
enum
{
	TFWeaponSlot_Primary,
	TFWeaponSlot_Secondary,
	TFWeaponSlot_Melee,
	TFWeaponSlot_Grenade,
	TFWeaponSlot_Building,
	TFWeaponSlot_PDA,
	TFWeaponSlot_Item1,
	TFWeaponSlot_Item2
};

// Identifiers for the eventtype property on the teamplay_flag_event event
enum {
	TF_FLAGEVENT_PICKEDUP = 1,
	TF_FLAGEVENT_CAPTURED,
	TF_FLAGEVENT_DEFENDED,
	TF_FLAGEVENT_DROPPED,
	TF_FLAGEVENT_RETURNED
};

enum TFResourceType
{
	TFResource_Ping,
	TFResource_Score,
	TFResource_Deaths,
	TFResource_TotalScore,
	TFResource_Captures,
	TFResource_Defenses,
	TFResource_Dominations,
	TFResource_Revenge,
	TFResource_BuildingsDestroyed,
	TFResource_Headshots,
	TFResource_Backstabs,
	TFResource_HealPoints,
	TFResource_Invulns,
	TFResource_Teleports,
	TFResource_ResupplyPoints,
	TFResource_KillAssists,
	TFResource_MaxHealth,
	TFResource_PlayerClass,
	TFResource_COUNT
};

static const char TFResourceNames[TFResource_COUNT][] =
{
	"m_iPing",
	"m_iScore",
	"m_iDeaths",
	"m_iTotalScore",
	"m_iCaptures",
	"m_iDefenses",
	"m_iDominations",
	"m_iRevenge",
	"m_iBuildingsDestroyed",
	"m_iHeadshots",
	"m_iBackstabs",
	"m_iHealPoints",
	"m_iInvulns",
	"m_iTeleports",
	"m_iResupplyPoints",
	"m_iKillAssists",
	"m_iMaxHealth",
	"m_iPlayerClass"
};

/**
 * Gets a client's current team.
 *
 * @param client        Client index.
 * @return              Current TFTeam of client.
 * @error               Invalid client index.
 */
stock TFTeam TF2_GetClientTeam(int client)
{
	return view_as<TFTeam>(GetClientTeam(client));
}

/**
 * Changes a client's current team.
 *
 * @param client        Client index.
 * @param team          TFTeam team symbol.
 * @error               Invalid client index.
 */
stock void TF2_ChangeClientTeam(int client, TFTeam team)
{
    ChangeClientTeam(client, view_as<int>(team));
}

/**
 * Gets a client's current class.
 *
 * @param client        Player's index.
 * @return              Current TFClassType of player.
 * @error               Invalid client index.
 */
stock TFClassType TF2_GetPlayerClass(int client)
{
	return view_as<TFClassType>(GetEntProp(client, Prop_Send, "m_iClass"));
}

/**
 * Sets a client's class.
 *
 * Note: If setting player class in a player spawn hook weapons should be set to false.
 *
 * @param client        Player's index.
 * @param classType     TFClassType class symbol.
 * @param weapons       This parameter is ignored.
 * @param persistent    If true, changes the player's desired class so the change stays after death.
 * @error               Invalid client index.
 */
stock void TF2_SetPlayerClass(int client, TFClassType classType, bool weapons=true, bool persistent=true)
{
	SetEntProp(client, Prop_Send, "m_iClass", view_as<int>(classType));

	if (persistent)
	{
		SetEntProp(client, Prop_Send, "m_iDesiredPlayerClass", view_as<int>(classType));
	}
}

/**
 * Retrieves client data from the resource entity
 *
 * @param client		Player's index.
 * @param type			ResourceType constant
 * @return				Value or -1 on failure.
 * @error				Invalid client index, client not in game or failed to find resource entity.
 * @deprecated          Use GetPlayerResourceEntity and GetEntProp instead.
 */
/////////////////////// Doesn't work with the latest SM 1.11's spcomp /////////////////////////////////////
// #pragma deprecated Use GetPlayerResourceEntity and GetEntProp instead
// stock int TF2_GetPlayerResourceData(int client, TFResourceType type)
// {
// 	if (!IsClientConnected(client))
// 	{
// 		return -1;
// 	}
// 
// 	int offset = FindSendPropInfo("CTFPlayerResource", TFResourceNames[type]);
// 
// 	if (offset < 1)
// 	{
// 		return -1;
// 	}
// 
// 	int entity = TF2_GetResourceEntity();
// 
// 	if (entity == -1)
// 	{
// 		return -1;
// 	}
// 
// 	return GetEntData(entity, offset + (client*4));
// }

/**
 * Sets client data in the resource entity
 *
 * Note: The game overwrites these values every frame, so changing them will have very little effect.
 *
 * @param client        Player's index.
 * @param type          ResourceType constant
 * @param value         Value to set.
 * @return              Value or -1 on failure.
 * @error               Invalid client index, client not in game or failed to find resource entity.
 * @deprecated          Use GetPlayerResourceEntity and SetEntProp instead.
 */
// #pragma deprecated Use GetPlayerResourceEntity and SetEntProp instead
// stock bool TF2_SetPlayerResourceData(int client, TFResourceType type, any value)
// {
// 	if (!IsClientConnected(client))
// 	{
// 		return false;
// 	}
// 
// 	int offset = FindSendPropInfo("CTFPlayerResource", TFResourceNames[type]);
// 
// 	if (offset < 1)
// 	{
// 		return false;
// 	}
// 
// 	int entity = TF2_GetResourceEntity();
// 
// 	if (entity == -1)
// 	{
// 		return false;
// 	}
// 
// 	SetEntData(entity, offset + (client*4), value);
// 
// 	return true;
// }

/**
 * Removes all weapons from a client's weapon slot
 *
 * @param client        Player's index.
 * @param slot          Slot index (0-5)
 * @error               Invalid client, invalid slot or lack of mod support
 */
stock void TF2_RemoveWeaponSlot(int client, int slot)
{
	int weaponIndex;
	while ((weaponIndex = GetPlayerWeaponSlot(client, slot)) != -1)
	{
		// Open Fortress doesn't have this netprop, so we're good
/*
		// bug #6206
		// papering over a valve bug where a weapon's extra wearables aren't properly removed from the weapon's owner
		int extraWearable = GetEntPropEnt(weaponIndex, Prop_Send, "m_hExtraWearable");
		if (extraWearable != -1)
		{
			TF2_RemoveWearable(client, extraWearable);
		}

		extraWearable = GetEntPropEnt(weaponIndex, Prop_Send, "m_hExtraWearableViewModel");
		if (extraWearable != -1)
		{
			TF2_RemoveWearable(client, extraWearable);
		}
*/
		RemovePlayerItem(client, weaponIndex);
		AcceptEntityInput(weaponIndex, "Kill");
	}
}

/**
 * Removes all weapons from a client
 *
 * @param client        Player's index.
 */
stock void TF2_RemoveAllWeapons(int client)
{
	for (int i = 0; i <= 5; i++)
	{
		TF2_RemoveWeaponSlot(client, i);
	}
}

/**
 * Gets a player's condition bits
 *
 * @param client        Player's index.
 * @return              Player's condition bits
 * @deprecated          Use TF2_IsPlayerInCondition instead.
 */
#pragma deprecated Use TF2_IsPlayerInCondition instead.
stock int TF2_GetPlayerConditionFlags(int client)
{
	return GetEntProp(client, Prop_Send, "m_nPlayerCond")|GetEntProp(client, Prop_Send, "_condition_bits");
}

/**
 * Check whether or not a condition is set on a player
 *
 * @param client        Player's index.
 * @param cond          TFCond constant
 * @return              True if set, false otherwise
 */
stock bool TF2_IsPlayerInCondition(int client, TFCond cond)
{
	// Conditions are stored across multiple netprops now, one for each 32-bit segment.
	int iCond = view_as<int>(cond);
	switch (iCond / 32)
	{
		case 0:
		{
			int bit = 1 << iCond;
			if ((GetEntProp(client, Prop_Send, "m_nPlayerCond") & bit) == bit)
			{
				return true;
			}

// Doesn't exist
//			if ((GetEntProp(client, Prop_Send, "_condition_bits") & bit) == bit)
//			{
//				return true;
//			}
		}
		case 1:
		{
			int bit = (1 << (iCond - 32));
			if ((GetEntProp(client, Prop_Send, "m_nPlayerCondEx") & bit) == bit)
			{
				return true;
			}
		}
		case 2:
		{
			int bit = (1 << (iCond - 64));
			if ((GetEntProp(client, Prop_Send, "m_nPlayerCondEx2") & bit) == bit)
			{
				return true;
			}
		}
		case 3:
		{
			int bit = (1 << (iCond - 96));
			if ((GetEntProp(client, Prop_Send, "m_nPlayerCondEx3") & bit) == bit)
			{
				return true;
			}
		}
		case 4:
		{
			int bit = (1 << (iCond - 128));
			if ((GetEntProp(client, Prop_Send, "m_nPlayerCondEx4") & bit) == bit)
			{
				return true;
			}
		}
		default:
		{
			ThrowError("Invalid TFCond value %d", iCond);
		}
	}

	return false;
}

/**
 * Gets an entity's object type.
 *
 * @param entity        Entity index.
 * @return              Current TFObjectType of entity.
 * @error               Invalid entity index.
 */
stock TFObjectType TF2_GetObjectType(int entity)
{
	int offset = GetEntSendPropOffs(entity, "m_iObjectType");

	if (offset <= 0)
	{
		ThrowError("Entity index %d is not an object", entity);
	}

	return view_as<TFObjectType>(GetEntData(entity, offset));
}

/**
 * Gets an entity's object mode.
 *
 * @param entity        Entity index.
 * @return              Current TFObjectMode of entity.
 * @error               Invalid entity index.
 */
stock TFObjectMode TF2_GetObjectMode(int entity)
{
	int offset = GetEntSendPropOffs(entity, "m_iObjectMode");

	if (offset <= 0)
	{
		ThrowError("Entity index %d is not an object", entity);
	}

	return view_as<TFObjectMode>(GetEntData(entity, offset));
}


native void TF2_IgnitePlayer(int client, int attacker);
native void TF2_RespawnPlayer(int client);
native void TF2_RegeneratePlayer(int client);
// inflictor is unused but exists for bcompat
native void TF2_AddCondition(int client, TFCond cond, float dur = TFCondDuration_Infinite, int inflictor = 0);
native void TF2_RemoveCondition(int client, TFCond cond);
native void TF2_DisguisePlayer(int client, TFTeam team, TFClassType classType, int target = 0);
native void TF2_RemovePlayerDisguise(int client);
native void TF2_StunPlayer(int client, float duration, float slowdown = 0.0, int stunflags, int attacker = 0);

forward void TF2_OnConditionRemoved(int client, TFCond cond);
forward void TF2_OnConditionAdded(int client, TFCond cond, float dur/*, int inflictor*/);
forward Action TF2_CalcIsAttackCritical(int client, int weapon, char[] weaponname, bool &result);

// Enough of that, here's some Open Fortress stuff

// post_inventory_application
forward void OF_OnPlayerRegenerated(int client);
// player_spawn
forward void OF_OnPlayerSpawned(int client);

// Should be used after TF2_RegeneratePlayer. Manages class weapons and arm models
native void OF_InitClass(int client);

enum
{
	// Live TF2 order first, then our custom ones
	TF_GAMETYPE_UNDEFINED = 0,
	TF_GAMETYPE_CTF, // Capture the Flag
	TF_GAMETYPE_CP, // Control Point
	TF_GAMETYPE_PAYLOAD, // Payload. NOTE: Live TF2 refers to this as ESCORT, but we use PAYLOAD instead as ESCORT is a different gamemode
	TF_GAMETYPE_ARENA, // Arena
	TF_GAMETYPE_MVM, // Mann vs Machine
	TF_GAMETYPE_RD, // Robot Destruction
	TF_GAMETYPE_PASSTIME, // Passtime
	TF_GAMETYPE_PD, // Player Destruction

	// open fortress
	TF_GAMETYPE_ESC, // Escort
	TF_GAMETYPE_DM, // Deathmatch
	TF_GAMETYPE_TDM, // Team Deathmatch
	TF_GAMETYPE_DOM, // Domination, also used with Escort
	TF_GAMETYPE_GG, // Gun Game
	TF_GAMETYPE_3WAVE, // 3 Wave
	TF_GAMETYPE_INF, // Infection
	TF_GAMETYPE_JUG, // Juggernaught

	TF_GAMETYPE_LAST
};

enum// TFGrenadeIDs
{
	TF_GRENADE_NONE = 0,

	TF_GRENADE_NORMAL,
	TF_GRENADE_NORMAL_ENGINEER,
	TF_GRENADE_CONCUSSION,
	TF_GRENADE_NAIL,
	TF_GRENADE_MIRV,
	TF_GRENADE_NAPALM,
	TF_GRENADE_GAS,
	TF_GRENADE_EMP,
	TF_GRENADE_CALTROP,
	TF_GRENADE_PIPEBOMB,
	TF_GRENADE_SMOKE_BOMB,
	TF_GRENADE_HEAL,
	TF_GRENADE_FLARE,
	TF_GRENADE_HALLUC,

	TF_GRENADE_COUNT
};

enum
{
	TF_PROJECTILE_NONE,
	TF_PROJECTILE_BULLET,
	TF_PROJECTILE_ROCKET,
	TF_PROJECTILE_PIPEBOMB,
	TF_PROJECTILE_PIPEBOMB_REMOTE,
	TF_PROJECTILE_SYRINGE,
	TF_PROJECTILE_NAIL,
	TF_PROJECTILE_TRIPMINE,
	TF_PROJECTILE_INCENDROCKET,
	TF_PROJECTILE_PIPEBOMB_DM,
	TF_PROJECTILE_TRANQ,
	TF_PROJECTILE_COOM,

	TF_NUM_PROJECTILES
};

enum
{
	TF_WEARABLE_NONE = 0,
	TF_WEARABLE_CAP,
	TF_WEARABLE_HELMET,
	TF_WEARABLE_COWBOY,
	TF_WEARABLE_YARR,
	TF_WEARABLE_HEADSET,
	TF_WEARABLE_SPYMASK,
	
	TF_WEARABLE_LAST
};

enum
{
	TF_CLASSMOD_NONE = 0,		// Sniper aiming, Heavy minigun.
	TF_CLASSMOD_TFC,
	TF_CLASSMOD_ZOMBIE,
	
	
	TF_CLASSMOD_LAST,
};

#define TFSTATE_GRENPRIMED		0x000001 // Whether the player has a primed grenade
#define TFSTATE_RELOADING		0x000002 // Whether the player is reloading
#define TFSTATE_ALTKILL			0x000004 // #TRUE if killed with a weapon not in self.weapon: NOT USED ANYMORE
#define TFSTATE_RANDOMPC		0x000008 // Whether Playerclass is random, new one each respawn
#define TFSTATE_INFECTED		0x000010 // set when player is infected by the bioweapon
#define TFSTATE_INVINCIBLE		0x000020 // Player has permanent Invincibility (Usually by GoalItem)
#define TFSTATE_INVISIBLE		0x000040 // Player has permanent Invisibility (Usually by GoalItem)
#define TFSTATE_QUAD			0x000080 // Player has permanent Quad Damage (Usually by GoalItem)
#define TFSTATE_RADSUIT			0x000100 // Player has permanent Radsuit (Usually by GoalItem)
#define TFSTATE_BURNING			0x000200 // Is on fire
#define TFSTATE_GRENTHROWING	0x000400  // is throwing a grenade
#define TFSTATE_AIMING			0x000800  // is using the laser sight
#define TFSTATE_ZOOMOFF			0x001000  // doesn't want the FOV changed when zooming
#define TFSTATE_RESPAWN_READY	0x002000  // is waiting for respawn, and has pressed fire
#define TFSTATE_HALLUCINATING	0x004000  // set when player is hallucinating
#define TFSTATE_TRANQUILISED	0x008000  // set when player is tranquilised
#define TFSTATE_CANT_MOVE		0x010000  // player isn't allowed to move
#define TFSTATE_RESET_FLAMETIME 0x020000 // set when the player has to have his flames increased in health
#define TFSTATE_HIGHEST_VALUE	TFSTATE_RESET_FLAMETIME

// items
#define IT_SHOTGUN				(1<<0)
#define IT_SUPER_SHOTGUN		(1<<1) 
#define IT_NAILGUN				(1<<2) 
#define IT_SUPER_NAILGUN		(1<<3) 
#define IT_GRENADE_LAUNCHER		(1<<4) 
#define IT_ROCKET_LAUNCHER		(1<<5) 
#define IT_LIGHTNING			(1<<6) 
#define IT_EXTRA_WEAPON			(1<<7) 

#define IT_SHELLS				(1<<8) 
#define IT_BULLETS				(1<<9) 
#define IT_ROCKETS				(1<<10) 
#define IT_CELLS				(1<<11) 
#define IT_AXE					(1<<12) 

#define IT_ARMOR1				(1<<13) 
#define IT_ARMOR2				(1<<14) 
#define IT_ARMOR3				(1<<15) 
#define IT_SUPERHEALTH			(1<<16) 

#define IT_KEY1					(1<<17) 
#define IT_KEY2					(1<<18) 

#define IT_INVISIBILITY			(1<<19) 
#define IT_INVULNERABILITY		(1<<20) 
#define IT_SUIT					(1<<21)
#define IT_QUAD					(1<<22) 
#define IT_HOOK					(1<<23)

#define IT_KEY3					(1<<24)	// Stomp invisibility
#define IT_KEY4					(1<<25)	// Stomp invulnerability
#define IT_LAST_ITEM			IT_KEY4

// Medikit
#define WEAP_MEDIKIT_OVERHEAL 50 // Amount of superhealth over max_health the medikit will dispense
#define WEAP_MEDIKIT_HEAL	200  // Amount medikit heals per hit

// This can only ever be used on a TakeHealth call, since it re-uses a dmg flag that means something else
#define DMG_IGNORE_MAXHEALTH	(DMG_BULLET)

enum
{
	OF_ALLOW_REPEAT_PLACEMENT				= 0x01,
	OF_MUST_BE_BUILT_ON_ATTACHMENT			= 0x02,

	OF_BIT_COUNT	= 2
};

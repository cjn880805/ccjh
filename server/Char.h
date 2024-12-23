// User.h: interface for the CUser class.
//
//////////////////////////////////////////////////////////////////////
#include <cstring>
#if !defined(AFX_USER_H__7E4E4240_647B_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_USER_H__7E4E4240_647B_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Container.h"

#define	DIFFERSTR(x, y)		(strcmp(x, y) != 0)
#define EQUALSTR(x, y)		(strcmp(x, y) == 0)
#define	RANDOM(x, y)		random(x)

#define CND_CONTINUE		1
#define CND_NO_HEAL_UP		2
#define IDLE_TIMEOUT		900

//NPC/Player 的基类
//每个玩家角色都拥有一个宠物，宠物的存盘文件和玩家的帐号一致。

typedef	int	BUSYFUNCTION(CChar * ob);
typedef int INTERRUPTFUNCTION(CChar * me, CChar * who, char * how);

class CChar : public CContainer
{
public:
	virtual void attack(CChar * opponent);

	void SendTable(const char * table_name, CMapping * table, int total, int page);
	
	void reset_level();
	
	int follow_me(CChar * me, char * dir);
	CChar * query_leader();
	void set_leader(CChar * me);
	virtual void is_defeated(CChar * winnder, CChar * failer);
	CMapping * query_action();

	LONG query_combat_exp();
	void remove_all_killer();
	void set_killer(CChar * ob);
	LONG query_valid_exp();
	LONG skill_need_points(const char * skill);
	virtual int recognize_apprentice(CChar * me);
	
	static int exp2level(MYLONG exp);
	static int level2skill(int lv);
	
	void GetStateMsg(char * msg);
	void SendState(CChar * me = NULL);
	virtual void init(CChar * me);
	
	void fight_ob(CChar * ob);
	void kill_ob(CChar * ob);
	int is_killing(CChar * ob);
	
	LONG query_condition(const char * cnd);
	void clear_condition();
	
	int is_fighting(CContainer * enemy =  NULL);
	int is_busy();

	void improve_skill(const char * skill, int amount, int weak_mode = 0);
	int skill_death_recover();
	int skill_death_penalty();
	
	CMapping * query_learned();
	CMapping * query_skills();
	CMapping * query_skill_prepare();
	CMapping * query_skill_map();
	int query_skill(const char * skill, int raw = 0);
	const char * query_skill_prepared(const char * skill);
	const char * query_skill_mapped(const char * skill);
	void prepare_skill(const char * skill, const char * mapped_to = NULL);
	void map_skill(const char * skill, const char * mapped_to = NULL);
	int delete_skill(const char * nSkill);
	int set_skill(const char * nSkill, int nLevel);
	
	void apply_condition(const char * cnd, LONG duration);
	int update_condition();

	virtual int prevent_learn(CChar * me, const char * skill);
	void set_title(const char * title);
		
	typedef map<LONG, LONG, less<LONG> >DTEquipList;
	typedef DTEquipList::iterator iterator_equip;

	static MYLONG Level2Exp(int lv);
	virtual void SendOff();
	
	void assign_apprentice(const char * title, int privs);
	void create_family(char * family, int generation, char *title);
	virtual void attempt_apprentice(CChar * me);
	int recruit_apprentice(CChar * me);
	int is_apprentice_of(CChar * me);


	CContainer * query_weapon();
	LONG query_str();
	LONG query_con();
	LONG query_int();
	LONG query_dex();
	
	void unconcious();
	virtual void die();
	int command(char * arg);	

	virtual int Save();
	virtual int Load();


	void start_busy(int nStart, INTERRUPTFUNCTION * new_interrupt = NULL);
	void interrupt_me(CChar * who, char * how );
	void start_busy(BUSYFUNCTION * new_busy, INTERRUPTFUNCTION * new_interrupt = NULL);

	LONG receive_healing(const char * type, LONG heal);
	LONG receive_curing(const char * type, LONG heal);
	LONG receive_damage(const char * type, LONG nDamage, CChar * who = NULL);
	LONG receive_wound(const char * type, LONG damage, CChar * me = NULL);

	int disable_player(const char * szType);
	int enable_player();

	virtual void setup();
	void heart_beat();
	static char * Wield_Position(int nPos);
	LONG Query_Equip(int nPos);
	DTEquipList * Get_EquipList();
	virtual LONG Query(int nAttr);
	CChar();
	virtual ~CChar();

public:
	int query_team();
	void revive(int quiet);

	int LoadFromTemp();
	int SaveToTemp();

	int LoadFromServer();
	int SaveToServer();
		
	int cmd_hit_ob(CChar * target, char * arg);
	int can_learn(const char * skillname);
	void FlushMySkill(CChar * me);
	void FlushMyEquip();
	void FlushMyInfo();
	int mini_skill();
	static void Remove_Betrayer(CChar * me);
	int query_unarmed();
	virtual void finish_kill(CChar * me);
	int learn_bonus();
	int refuse_channel(const char * channel);
	LONG query_apply(const char * attr);
	
	int query_kar();
	int is_loading();
	CContainer * query_shield();
	int query_grant();
	virtual int do_look(CChar * me);
	int recruit_num();
	void release_master();
	void remove_killer(CChar * ob);
	virtual void relay_say(CChar * me, char * msg);
	virtual void relay_emote(CChar * me, string verb);
	int query_per();
	static void remove_faint(CContainer * me, LONG param1, LONG param2);
	//角色的图片号定义
	enum
	{
		picture_default = 0,
		young_woman1,
		young_woman2,
		young_woman3,
		young_woman4,
		young_woman5,
		young_woman6,
		young_woman7,
		young_woman8,
		young_woman9,
		young_woman10,
		young_woman11,
		young_woman12,
		young_man1,
		young_man2,
		young_man3,
		young_man4,
		young_man5,
		young_man6,
		old_man1,
		old_man2,
		old_woman,
		boy1,
		girl1,
		girl2,
		boy2,
		young_monk,					//小和尚
		old_monk,					//老和尚
		young_nun,					//小尼姑
		taoist,
		taoist_with_sword,	
		taoistess,				//女道士
		triggerman1,			//镖师1
		triggerman2,
		pawnshop_boss,			//当铺老板
		drugstore_boss,			//药铺老板
		pub_boss,				//酒店老板
		smith_boss,				//铁匠老板
		masked_man,				//蒙面人
		cateran,				//山贼
		banditi,				//土匪
		officer,				//官府老爷
		general,				//武将
		guarder,				//官兵
		tipstaff,				//衙役
		boar,					//野猪
		straw_man,				//稻草人
		tiger,					//老虎
		snake,					//蛇
		dog,					//狗
		begger,					//乞丐
		waiter,					//店小二
		old_nun,				//老尼姑
	};

protected:
	int LoadObjectFromTemp();
	int LoadObjectFromServer();
	int SaveObjectToTemp();
	int SaveObjectToServer();

	int GetSaveData(CMapping * save);	
	int RestoreData(CMapping * save);

	const char * inventory_look(CContainer * item, int flag);

	int Heal_Up();	

	void continue_action();
	
	//装备位置
	DTEquipList			m_EquipList;		//装备位置

	int					m_nTick;
	int					m_nTickTwo;
	int					m_wait_loading;		//切换地图等待

	int					m_nBusy;
	BUSYFUNCTION		*	m_Busy;
	INTERRUPTFUNCTION	*	m_Interrupt;
	
	int		m_nRevive;							//苏醒秒数

	CMapping skills;
	CMapping learned;
	CMapping skill_map;
	CMapping skill_prepare;

	CVector		m_Killers;			//敌人

	CChar *		m_Leader;

	CMapping friends;
	int m_nSaveCount;
};

void setup_char(CChar * me);

#endif // !defined(AFX_USER_H__7E4E4240_647B_11D4_98AB_0050BABC5212__INCLUDED_)

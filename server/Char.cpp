// User.cpp: implementation of the CChar class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Globle.h"
#include "Char.h"
#include "User.h"
#include "Npc.h"
#include "Skill.h"
#include "CmdHandle.h"
#include "Room.h"
#include "Condition.h"
#include "Channel.h"
#include "../combat/Combatd.h"

#include "../std/FightRoom.h"
#include "../std/Corpse.h"

void setup_char(CChar * me);
void DropAll(CChar * me);

CCmdHandle CommandHandle;

const char * query_waimao(string gender, int per);
const char * query_rank(CChar * ob);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#define MAX_OPPONENT   4

CChar::CChar()
{
	//DEFAULT:
	m_nBusy = 0;
	m_Busy = 0;
	m_Interrupt = 0;
	m_nRevive = 0;

	m_nTick = 0;
	m_nTickTwo = 0;
	m_wait_loading = 0;

	set("gender", "����");

	set_temp("max_items", 100);

	m_Leader = 0;
	m_nSaveCount = 0;	
}

CChar::~CChar()
{
	m_EquipList.clear();
}

LONG CChar::Query(int nAttr)
{
	switch(nAttr)
	{
	case IS_CHAR:
		return 1;

	case CAN_GET: 
		return ! Query(IS_LIVING);

	case IS_LIVING:
		{
			if( querystr_temp("disabled")[0] )
				return 0;
			return 1;
		}
	case IS_BUSY:
		return m_Busy != NULL;
	}

	return CContainer::Query(nAttr);
}

//���ü���
int CChar::set_skill(const char * skill, int nLevel)
{
	CSkill * sk = load_skill(skill);
	
	if(! sk)
	{ 
		output_error("F_SKILL: No such skill (%s)", skill);
		return 0;
	}

	skills.set(skill, nLevel);
	return 1;
}

int CChar::delete_skill(const char * skill)
{
	if(! skill[0]) return 0;
	if(skills.undefinedp(skill))
		return 0;

	skills.del(skill);
	learned.del(skill);

	return 1;
}

CChar::DTEquipList * CChar::Get_EquipList()
{
	return &m_EquipList;
}

//����װ��λ�õ�����
LONG CChar::Query_Equip(int nPos)
{
	iterator_equip p;

	p = m_EquipList.find(nPos);
	if( p == m_EquipList.end())
		return 0;
	return p->second;
}

//����
void CChar::heart_beat()
{
	int wimpy_ratio;
	LONG object_id = m_lObjectID;
	
	if(! environment()) return;
	if(is_loading()) 
	{
		m_wait_loading++;
		if(m_wait_loading > 5 && userp(this))	//5����Զ������ͼ
		{
			//��������
			command("loc 0 0 0");

//			char msg[255];
//			g_Channel.do_channel(&g_Channel, NULL, "sys", snprintf(msg, 255, "%s�л���ͼtime out���Զ������ͼ��", name(1)));			
		}		

		return;		//�����ͼʱ��ͣ����
	}

	m_wait_loading = 0;

	CContainer::heart_beat();
	
	//�ж��Ƿ��Ѿ����ӳٺ�ʽ������
	if(g_LastDestructObject == object_id)
		return;

	if(m_nRevive)
	{
		if(! --m_nRevive)
			revive(0);
	}

	if( query("eff_hp") < 0 )
	{
		//QUEST->quest_kill(this_object());	����
		die();
		return;
	}

	if(query("hp") < 0 )
	{
		if(! Query(IS_LIVING) ) die();
		else unconcious();
//		ASSERT(this);
		return;		//���뷵�أ���Die�У���������ѱ����١�
	}

	if(userp(this))
	{
		m_nSaveCount ++;
		if(m_nSaveCount >= 100)
		{			
			m_nSaveCount = random(40);		
			if(userp(this)) Save();			//auto save
		}

		SendOff();
	}	

	if( is_busy() ) 
	{
		continue_action();
		// We don't want heart beat be halt eventually, so return here.
		return;
	}
	
	//ս��������
	if( is_fighting() && (wimpy_ratio = query("env/wimpy") )
			&& ( query("hp") * 100 / query("max_hp") <= wimpy_ratio) )
	{
		command("halt");		
	}
			
	//NPC Random Action
	if(Query(IS_NPC))
	{
		//�п����Ѿ��ͷ�
		if(((CNpc *)this)->Self_Action())
		{
			if(object_id == g_LastDestructObject)
				return;		
		}
	}

	if( m_nTick--  ) return;
	else 
	{
		m_nTick = 5 + random(5);
		m_nTickTwo++;		
	}
	
	int cnd_flag = update_condition();
	
	if(m_nTickTwo < 8)	//40 ~ 80 s��һ��
		return;
	
	m_nTickTwo = 0;
	
	if( Heal_Up() &&  ! (cnd_flag & CND_NO_HEAL_UP) )
	{
		SendState(this);	
	}
	else if( ! is_fighting() 
			&& ! m_CalloutList.GetCount()
			&& ! query("chat_chance") 
			&& ! Query(IS_USER) )

		set_heart_beat(0);

	if(! Query(IS_USER)) return;

	time_t offtime;

	if((offtime = query_temp("net_dead")))	//������
	{
		if( current_time - offtime > 600 		//���߳���10���ӣ����˳���Ϸ��
			&& command("quit"))
				return;
	}

	((CUser *)this)->update_age();

	if(g_Combatd.query("kick_idle"))
	{
		if( ((CUser *) this)->query_idle() > IDLE_TIMEOUT && !wizardp(this) )
		{
			((CUser *)this)->user_dump();
		}
	}
}

//��ʼ��
void CChar::setup()
{
	set_heart_beat(1);
	m_nTick = 5 + random(10);
        enable_player();
	
	setup_char(this);

	char msg[255];
	//���þ���
   if(querymap("corps"))
   {		
	    CRoom * r = load_room(querystr("corps/id"));
		if(r->query("fail_ob"))
			del("corps");
		else
		{
			set_temp("c_title", snprintf(msg, 255, "%s%s%s", 
				querymap("freedom") ? "* " : "",
				r->name(1), querystr("corps/rank")));
		}
   }
   else
   {	
		if(querymap("freedom"))
			set_temp("c_title", snprintf(msg, 255, "* %s", querystr("title")));
		else
			delete_temp("c_title");
   }

   del("c_title");
}

int CChar::enable_player()
{
	delete_temp("disabled");
	SendState();
	return 1;
}

int CChar::disable_player(const char * szType)
{
	set_temp("disabled", szType);
	SendState();
	return 1;
}

LONG CChar::receive_damage(const char * szType, LONG nDamage, CChar *who)
{
	int val;

	if( nDamage <= 0 ) return 0;					// error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
	if( DIFFERSTR(szType, "hp") && DIFFERSTR(szType , "mp") ) return 0;	// error("F_DAMAGE: �˺��������( ֻ���� ����֮һ )��\n");

	if(who)
		set_temp("last_damage_from", who->object_id());
//	else
//		delete_temp("last_damage_from");

	val = query(szType) - nDamage;

	if( val >= 0 ) 
		set(szType, val);
	else
	{
		set( szType, -1 );
        
		if(who && living(this) && userp(who) && ! querystr_temp("last_fainted_from")[0])
        {
			set_temp("last_fainted_from", who->querystr("id"));
			if(userp(this))
				call_out(remove_faint, 60);
        }
	}

	set_heart_beat(1);

	return nDamage;
}



LONG CChar::receive_wound(const char * type, LONG damage, CChar * who)
{
	LONG val;
	char eff_key[20];
	
	if( damage <= 0 ) return 0;
	if( DIFFERSTR(type, "hp") && DIFFERSTR(type, "mp") ) return 0;

	snprintf(eff_key, 20, "eff_%s", type);

	if( who ) 
		set_temp("last_damage_from", who->object_id());
//	else
//		delete_temp("last_damage_from");

	val = query(eff_key) - damage;

	if( val >= 0 ) set(eff_key, val);
	else 
	{
		set( eff_key,  -1);
		val = -1;

		if( who && living(this) && userp(who) && ! querystr_temp("last_fainted_from")[0])
        {
			set_temp("last_fainted_from",who->querystr("id"));
			if(userp(this))
				call_out(remove_faint, 60);
		}
	}
    
	if( query(type) > val ) set(type, val);

	set_heart_beat(1);
	return damage;
}

LONG CChar::receive_curing(const char * szType, LONG heal)
{
	int max, val;
	char max_key[20], eff_key[20];

	if( heal < 0 ) return 0;	//error("F_DAMAGE: �ָ�ֵΪ��ֵ��\n");
	if( DIFFERSTR(szType, "hp") && DIFFERSTR(szType, "mp") ) return 0; //error("F_DAMAGE: �ָ��������( ֻ����  ����֮һ )��\n");
	
	snprintf(max_key, 20, "max_%s", szType); 
	snprintf(eff_key, 20, "eff_%s", szType);

	val = query(eff_key);
	max = query(max_key);

   if( val + heal > max ) 
   {
	   set(eff_key, max);
     return max - val;
   }
   else {
     set( eff_key, val + heal);
     return heal;
   } 
}

LONG CChar::receive_healing(const char * szType, LONG heal)
{
	int val;
	int nEff;
	const char * eff_key;
	
	if( heal < 0 ) return 0;	//error("F_DAMAGE: �ָ�ֵΪ��ֵ��\n");
	if( DIFFERSTR(szType, "hp") && DIFFERSTR(szType, "mp") ) return 0;	//error("F_DAMAGE: �ָ��������( ֻ����  ����֮һ )��\n");

	if(EQUALSTR(szType, "hp")) eff_key = "eff_hp";
	else eff_key = "max_mp";

	nEff = query(eff_key);
	val = query(szType);

	//���val > nEff��������
	if(val >= nEff) return 0;

	if(val + heal > nEff)
	{
		set(szType, nEff);
		return nEff - val;
	}
	else
	{
		set(szType, val + heal);
		return heal;
	}
}

//��ѯһЩ���ԣ������������ֵ
void CChar::start_busy(BUSYFUNCTION * new_busy, INTERRUPTFUNCTION * new_interrupt)
{
	if( ! new_busy ) return;

	//ԭ����BUSY��ֹ lanwood 2001-09-24
	if(m_Interrupt) 
		( * m_Interrupt)(this, this, "next_busy");

	if(m_nBusy)	m_nBusy = 0;
	m_Busy = new_busy;
	m_Interrupt = new_interrupt;
	set_heart_beat(1);
}

void CChar::start_busy(int nStart, INTERRUPTFUNCTION * new_interrupt )
{
	if(! nStart) return;

	//ԭ����BUSY��ֹ lanwood 2001-09-24
	if(m_Interrupt) 
		( * m_Interrupt)(this, this, "next_busy");
	
	if(m_Busy) m_Busy = 0;		//�����
	m_nBusy = nStart;

	m_Interrupt = new_interrupt;
	set_heart_beat(1);
}

void CChar::continue_action()
{
	if( m_nBusy > 0 )
	{
		m_nBusy --;
		return;
	}
	
	if( m_Busy )
	{
		if( ! (* m_Busy)(this) )
		{
			m_Busy = 0;
			m_Interrupt = 0;
		}
	} 
	else
	{
		m_Busy = 0;
		m_Interrupt = 0;
	}
}

//���Busy
void CChar::interrupt_me(CChar *who, char * how)
{
	if( ! m_Busy && ! m_nBusy ) return;
	if( ! m_Interrupt ) return;

	if( ( * m_Interrupt)(this, who, how) )
	{
        m_Busy = 0;
		m_nBusy = 0;
        m_Interrupt = 0;
    }	
}

//���浽������
int CChar::SaveToServer()
{
	if(query("guest")) return 0;

//	SaveObjectToServer();

	//�ٴ��������ž���Ĵ���
	//lanwood 2001-02-25

	//begin--------
	LONG combat_exp = query("combat_exp");
	if( combat_exp < 50000)	//50000���²��ܸ�ʦ�����ž���
	{
		LONG addexp = query("combat_exp") - query("family/last_exp");
		if(query("family/user") )
		{
			//ÿ100�㣬10000����2�㣬50000����1��
			if(combat_exp < 10000)
				addexp *= 2;

			char master[40];
			
			strncpy(master, querystr("family/master_id"), 40);
			char key[80];

			CMapping * ptr = g_Channel.query_recruit(master);
			if(ptr)
				addexp += ptr->query(snprintf(key, 80, "%s/exp", querystr("id")));
				
			g_Channel.update_recruit(master, id(1), name(1), addexp, 1);

			//�����ž�����ɵ�ǰ���顣
			set("family/last_exp", query("combat_exp"));
		}
	}

	CMapping savedata;
	GetSaveData(&savedata);

#ifdef _SQL_		//���ݿ�
	const char * attr = savedata.GetBuffer();
	CContainer * coin = PresentName("coin", IS_ITEM);
	LONG money = query("balance");
	if(coin)
		money += coin->Query_Amount();

	char logintime[80], savetime[80];
	time_t current = query("login/time");
	struct tm * newtime;
	newtime = localtime( &current ); 

	sprintf(logintime, "%d/%02d/%02d %02d:%02d:%02d",
		1900 + newtime->tm_year, newtime->tm_mon + 1, newtime->tm_mday, 
		newtime->tm_hour, newtime->tm_min, newtime->tm_sec);

	current = current_time;
	newtime = localtime( &current ); 

	sprintf(savetime, "%d/%02d/%02d %02d:%02d:%02d",
		1900 + newtime->tm_year, newtime->tm_mon + 1, newtime->tm_mday, 
		newtime->tm_hour, newtime->tm_min, newtime->tm_sec);
			
	char * pData = NULL;
	int len = 1024 + strlen(attr);

	pData = new char[len];
	if(! pData)
	{
		fprintf(stderr, "Char::SaveToServer pData new is NULL! %s(%s)", name(1), id(1));
		output_error("Char::SaveToServer pData new is NULL! %s(%s)", name(1), id(1));
		return 0;
	}
	
	snprintf(pData, len, "update ccjhdb set cc_name='%s', cc_str=%ld, cc_int=%ld, "
			"cc_con=%ld, cc_dex=%ld, cc_family='%s', cc_age=%d, cc_gender='%s', "
			"cc_master='%s', cc_nickname='%s', cc_rank='%s', cc_class='%s', cc_level=%d, "
			"cc_ip = '%s', cc_balance = %ld, cc_logintime = '%s', cc_savetime = '%s', "
			"cc_experice=%ld, cc_repute=%ld, cc_grant=%d, cc_savedata='%s' where cc_id=%s",
		name(1),
		query("str"), query("int"), query("con"), query("dex"),
		querystr("family/family_name"), 
		query("age"), querystr("gender"),
		querystr("family/master_name"),
		querystr("nickname"),
		query_rank(this),
		querystr("class"),
		query("level"),
		GetIP(this), money, logintime, savetime,
		query("combat_exp"),
		query("repute"),
		query("grant"),
		attr,
		id(1));
	//������Ҫ�仯
	int nTmp = mysql_real_query(&mysql, pData, strlen(pData));

	delete []pData;

	if(nTmp != 0)
	{
		fprintf(stderr, "Save %s(%s) Error: %s", name(1), id(1), mysql_error(&mysql));
	}

	return !nTmp;

#else

	char fname[80];
	snprintf(fname, 80, "data/user/%s.o", querystr("id"));	
	return SaveToLocal(fname, &savedata);

#endif
	
}

//��ʱ�洢
int CChar::SaveToTemp()
{
	char fname[80];
	CMapping savedata;

	LONG myid = atol(querystr("id"));
	snprintf(fname, 80, "data/user/%ld/%ld.o", 1 + myid % 25, myid);
	
//	SaveObjectToTemp();

	GetSaveData(&savedata);
	return SaveToLocal(fname, &savedata);
}

//����,�ݴ�
int CChar::Save()
{
	//�ÿͲ��ܴ���
	if(query("guest")) return 0;
	if(! Query(CAN_SAVE)) return 0;
	
	if(! userp(this))
	{
		CMapping savedata;
		GetSaveData(&savedata);
		return CContainer::_Save(&savedata);		
	}

	//����ݴ�ʱ�䳬��һ��Сʱ,�����ô���һ��
	if(current_time > query_temp("save_to_server"))
	{
		SaveToServer();
		set_temp("save_to_server", current_time + 3600);
	}
	
#ifdef WIN32
	return SaveToServer();
#else
	return SaveToTemp();
#endif

}

//��ô�������
int CChar::GetSaveData(CMapping *save)
{
	save->set("dbase", _M);
	save->set("skills", skills);
	save->set("learned", learned);
	save->set("skill_map", skill_map);
	save->set("skill_prepare", skill_prepare);

	if(userp(this))
	{
		//------���¼���--------------------
		CMapping auto_load;
		POSITION p;
		CContainer * obj;
		char msg[80];
		int i=0;

		p = m_ItemList.GetHeadPosition();
		while(p)
		{
			obj = m_ItemList.GetNext(p);
			//if(! obj->query_autoload() ) continue;		//�ǿ��Զ�װ������������
			auto_load.set(
				snprintf(msg, 80, "%s,%ld:%ld", 
					obj->querystr("base_name"), obj->query("index"), i++), 
				obj->Query_Amount());

			obj->Save();
		}

		save->set("auto_load", auto_load);	

		//------���¼���--------------------
	}

	return 1;
}

//�ָ���������
int CChar::RestoreData(CMapping * save)
{	
	_M.copyMapping(save->querymap("dbase"));
	
	skills.copyMapping(save->querymap("skills"));
	learned.copyMapping(save->querymap("learned"));
	skill_map.copyMapping(save->querymap("skill_map"));
	skill_prepare.copyMapping(save->querymap("skill_prepare"));
	
	//-----------���ݾɰ汾-----------------
	CContainer * obj;	
	CVector v;
	CMapping auto_load;
	

	auto_load.copyMapping(save->querymap("auto_load"));
	auto_load.keys(v);

	set("infinity", 1);

	char str[80];

	for(int i=0; i<v.count(); i++)
	{
//		set_temp("load_old", 1);
		strncpy(str, v[i], 80);
	
		char * ptr = strstr(str, ",");
		if(ptr)
		{
			(* ptr) = 0;
			obj = load_item(str);

			char * ptr2 = strstr(ptr + 1, ":");
			if(ptr2) (* ptr2) = 0;

			obj->create(atol(ptr + 1));
		}
		else
			obj = load_item(str);

		obj->set_amount(auto_load[v[i]]);	
		obj->move(this);
	}

	del("infinity");
	//-----------���ݾɰ汾-----------------
	
	friends.copyMapping(g_Channel.query_friends(id(1)));
	return 1;
}

int CChar::LoadFromTemp()
{
	CMapping savedata;
	char fname[40];
	LONG myid = atol(querystr("id"));
	snprintf(fname, 80, "data/user/%ld/%ld.o", 1 + myid % 25, myid);

	if(! LoadFromLocal(fname, &savedata))
		return 0;

	if(! RestoreData(&savedata))
		return 0;
/*
	if(! query_temp("load_old"))
	{
		set("infinity", 1);
		//�������
		if(! LoadObjectFromTemp())
			return 0;

		del("infinity");		
	}
*/
	return 1;
}

//�ӷ�����װ��
int CChar::LoadFromServer()
{
	CMapping savedata;
	
#ifdef _SQL_

	char szQuery[512];
	MYSQL_RES *result = NULL;

	snprintf(szQuery, 512, "select cc_savedata from ccjhdb where cc_id=%s", querystr("id"));
	int nResult = mysql_real_query(&mysql, szQuery, strlen(szQuery));
	if( nResult != 0)
	{
		output_error("query db fail!");
		return FALSE;
	}
	result = mysql_store_result(&mysql);
	if(result == NULL)
	{
		output_error("database fail: store null");
		return FALSE;
	}
	int n = mysql_num_rows(result);
	if(n == 0)
	{
		mysql_free_result(result);
		return FALSE;		
	}

	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	if(row == NULL || row[0] == NULL)
	{
		mysql_free_result(result);
		return FALSE;
	}
	
	savedata.LoadBuffer(row[0]);
	mysql_free_result(result);

#else

	char fname[40];
	snprintf(fname, 80, "data/user/%s.o", querystr("id"));
	
	if(! LoadFromLocal(fname, &savedata))
		return 0;

#endif

	if(! RestoreData(&savedata))
		return 0;
/*
	if(! query_temp("load_old"))
	{
		set("infinity", 1);

		if(! LoadObjectFromServer())
		{
			output_error("%s����������ʧ��.", name(1));
		}
			
		del("infinity");
	}
*/
	return 1;
}

int CChar::Load()
{
	if(! userp(this))
	{
		CMapping save;
		if(! CContainer::_Load(&save))
			return 0;

		return RestoreData(&save);
	}
	else
	{
		return LoadFromTemp();			
	}

	return 1;
}
		
//����ָ��
int CChar::command(char * arg)
{
//	if(! Query(IS_LIVING)) return 0;		//����ִ��ָ�
	return CommandHandle.command(arg, this);
}

//װ��λ��debug function
char * CChar::Wield_Position(int nPos)
{
	static char sz[][5]={"��", "ͷ", "���", "�Ҷ�", "��", "��", "����", "����", "��",
					"����", "����", "��", "����", "����", "ѥ��", "����"};

	return sz[nPos];
}

//�����趨�ȼ�
void CChar::reset_level()
{	
	if(! Query(IS_USER)) return;

	while(query_valid_exp() < 0)
	{
		if(query("level") == 1) break;

		add("level", -1);		
	}

	setup_char(this);
}

//����
void CChar::die()
{
	CChar * killer;
	CChar * owner;

	//���䲻����
	if(querymap_temp("biwu"))
	{		
		revive(1);
		set("eff_hp", query("max_hp"));
		set("hp", 0l);
		message_vision("\n$N���������һ��������е������п���ͣ���������ˣ�\n", this);
		return;
	}
	//���ɴ���
	if(load_room("pk")->query("���ɴ���/start"))
	{
		char msg[255];
		CContainer * env = environment();
		if(((CChar *)env)->Query(CChar::IS_USER))
		{
			env=env->environment();
		}
		if(EQUALSTR(env->querystr("base_name"),"fight_room"))
		{
			env=env->environment();
		}
		if(env->query("���ɴ���") && query_temp("���ɴ���/online"))//�ڱ��䳡�е�ս��
		{
			if( (killer = (CChar *)find_object(query_temp("last_damage_from"), 1)) )
			{
				if( killer->Query(CChar::IS_USER) )
				{				   
					if(Query(CChar::IS_USER))
					{
						//���owner
						owner = (CChar *)find_object(query_temp("fight/owner"), 1);
						if(owner && owner->query_temp("fight/will_nk") == object_id())
							killer = owner;
						
						//char msg[255];
						revive(1);
						remove_all_killer();
						set("eff_hp", query("max_hp"));
						set("hp", 100);
						set_temp("���ɴ���/die",1);//���ɴ�ս����̭

						CContainer * env1 = load_room("pk");
						if(DIFFERSTR(querystr("family/family_name"),killer->querystr("family/family_name")))
						{
							int point=query("combat_exp")/5000;
							killer->add_temp("���ɴ���/count",point);//������ʤ�ߵķ���
							tell_object(killer, snprintf(msg, 255,"\n$HIR��սʤ����%s(%s)�����%d��Ļ��֣�ͬʱ������ɻ���������%d�㡣\n",name(1), id(1),point,point));
							
							snprintf(msg, 255, "���ɴ���/%s/point",killer->querystr("family/family_name"));
							env1->add(msg,point);//���ɻ���
						}
						snprintf(msg, 255, "���ɴ���/%s/die_count",querystr("family/family_name"));
						env1->add(msg,1);
						
						snprintf(msg, 255, "%s����%s(%s)�ڱ������������������в���%s����%s(%s)����̭���֡�", querystr("family/family_name"),name(1), id(1), killer->querystr("family/family_name"), killer->name(1), killer->id(1));
						g_Channel.do_channel(&g_Channel, 0, "rumor", msg);
						move(load_room(querystr("start_city")) );
						//delete_temp("���ɴ���"); //�����Ϣ��������ֻҪ���ɻ�ʤ������̭Ҳ�ɻ�ý���
						return ;
					}
				}
			}
		}
	}
	//������PK����
	if(load_room("pk")->query("PK����"))
	{
		if( (killer = (CChar *)find_object(query_temp("last_damage_from"), 1)) )
		{
			if( killer->Query(CChar::IS_USER) )
			{				   
				if(Query(CChar::IS_USER))
				{
					//���owner
					owner = (CChar *)find_object(query_temp("fight/owner"), 1);
					if(owner && owner->query_temp("fight/will_nk") == object_id())
						killer = owner;
					
					char msg[255];
					revive(1);
					remove_all_killer();
					set("eff_hp", query("max_hp"));
					set("hp", 100);
					killer->add_temp("pk����/count",1);
					delete_temp("pk����/count");
					snprintf(msg, 255, "%s(%s)�ڱ���PK�����в���%s(%s)����ܶ��飬%s(%s)�Ѿ�������ʤ%d����", name(1), id(1), killer->name(1), killer->id(1), killer->name(1), killer->id(1),killer->query_temp("pk����/count"));
					g_Channel.do_channel(&g_Channel, 0, "rumor", msg);
					move(load_room(querystr("start_city")) );
					return ;
				}
			}
		}
	}
	g_Combatd.Announce(this, "dead");
	if( ! Query(IS_LIVING) ) revive(1);
	
	del("condition");		//�������condition
	
	//������
	if( (query("kill/flee") - query("kill/death")) > 0)
	{		
		add("kill/death", 1);
		
		remove_all_killer();
		
		set("hp", 1);  set("eff_hp", query("max_hp") / 2);
		set("mp", 0l);  
		
		DropAll(this);
		message_vision("$N�ƺ������鱣�ӣ�����֮��ת�����������������ص����壬��Զ����ȥ��", this);
		move(load_room(querystr("start_city")) );		
		return;
	}
	add("death_times",1);//����������¼

	//�����ͷ�
	if( (killer = (CChar *)find_object(query_temp("last_damage_from"), 1)) )
	{
		//���owner
		owner = (CChar *)find_object(query_temp("fight/owner"), 1);
		if(owner && owner->query_temp("fight/will_nk") == object_id())
			killer = owner;

		g_Combatd.Killer_Reward(killer, this);	
		killer->remove_killer(this);
		//������
		if(userp(killer)) killer->Save();

		killer->finish_kill(this);	//lanwood 2001-04-12
	}
	else
	{
		//û��killer�����ж�
        if(Query(IS_USER)) 
		{
            g_Combatd.Victim_Penalty(this);
	    }
	}

	CContainer * env = this;
	while(env->environment())
		env = env->environment();

	if(! env->query("PK") )
		CCorpse::MakeCorpse(this, killer);

	if(userp(this)) Save();
		
	if( Query(IS_USER) )
	{		
		remove_all_killer();

		set("hp", 1);  set("eff_hp", query("max_hp") / 2);
		set("mp", 0l);  
     
		CRoom * room = load_room(querystr("start_city"));
		if(room)
		{
			move(room);
//			if(sprite) sprite->move(room);
		}
		else
		{
			output_error("�û�%sû�л���%ld\n", name(1), query("start_city"));
		}

		FlushMyInfo();
		FlushMySkill(this);
    } else
		DESTRUCT_OB(this, "CChar::die");

}

//����
void CChar::unconcious()
{
	if( ! Query(IS_LIVING)) return;
	
    MessageVision(this, "tell", "�����ǰһ�ڣ�����ʲôҲ��֪���ˣ�����");
	disable_player("���Բ���");
	set("hp", 0L);
	set("mp", 0L);
	set_temp("block_msg/all", 1);
	g_Combatd.Announce(this, "unconcious");
	m_nRevive = random(100 - query("con")) + 30;	//30������������
}

//����
void CChar::revive(int quiet)
{
	m_nRevive = 0;
		
	while( environment()->Query(IS_CHAR))
		move(environment()->environment());
   
	enable_player();
	if( !quiet ) 
	{
		g_Combatd.Announce(this, "revive");
		delete_temp("block_msg/all");
		MessageVision(this, "tell", "������������������֪��������");
	}
	else
		delete_temp("block_msg/all");
}

//����ʱ�ָ�
int CChar::Heal_Up()
{
	int update_flag = 0;
	LONG addhp = 0;
	LONG m_lHP, m_lHP_Eff, m_lHP_Max;

	m_lHP = query("hp");
	m_lHP_Eff = query("eff_hp");
	m_lHP_Max = query("max_hp");

	addhp = query("con") / 3;
	m_lHP = add("hp", addhp);
	if( m_lHP >= m_lHP_Eff )
	{
		set("hp", m_lHP_Eff);
		if( m_lHP_Eff < m_lHP_Max )
		{ 
			add("eff_hp", 1);
			update_flag++; 
		}
	}
	else 
		update_flag++;

	return update_flag;
}

LONG CChar::query_str()
{
	return query("str") + query_temp("apply/str") + query_unarmed() / 10;
}

LONG CChar::query_con()
{
	return query("con") + query_temp("apply/con") + query_skill("force", 1) / 10;
}

LONG CChar::query_int()
{
	return query("int") + query_temp("apply/int") + query_skill("literate", 1) / 10;
}

LONG CChar::query_dex()
{
	return query("dex") + query_temp("apply/dex") + query_skill("dodge", 1) / 10;
}

//��������
CContainer * CChar::query_weapon()
{
	LONG weapon = Query_Equip(WIELD_RIGHT_HAND);
	if(! weapon) weapon = Query_Equip(WIELD_BOTH_HAND);
	if(! weapon) return 0;

	CContainer * ob = Present(weapon);
	if(! ob || ! ob->querystr("skill_type")[0]) return 0;

	return ob;
}

//��ʦͽ��ϵ
int CChar::is_apprentice_of(CChar *me)
{
	const char * bangpai = querystr("family/family_name");
   
	if( ! bangpai[0] ) return 0;

	if( EQUALSTR(querystr("family/master_id"), me->querystr("id"))
		&& EQUALSTR(bangpai, me->querystr("family/family_name")))
     return 1;

   return 0;  
}

//��ͽ
int CChar::recruit_apprentice(CChar *me)
{
	CMapping * my_family, family;

	if( me->is_apprentice_of( this ) )   return 0;
	if( !( my_family = querymap("family")) ) return 0;

	family.set("master_id", id(1));
	family.set("master_name", name(1));
	family.set("family_name", my_family->querystr("family_name"));
	family.set("generation", my_family->query("generation") + 1);
	family.set("enter_time", current_time);

	//begin---- ��ͽ���� lanwood 2001-02-25
	if(userp(this))
	{
		family.set("last_exp", me->query("combat_exp"));
		family.set("user", 1);
	}
	
	//�޸�ԭ��ʦ������ͽ��¼
	me->release_master();
	//end------

	me->set("family", family);
	me->assign_apprentice("����", 0);

	//����me�Ĳ˵�
	DownLoad(me);

   return 1;
}

void CChar::attempt_apprentice(CChar *me)
{

}

void CChar::create_family(char * family_name, int generation, char *title)
{
	CMapping family;

	family.set("family_name", family_name);
	family.set("generation", generation);
	set("family", family);

	// priv = -1 for ALL privileges.
	assign_apprentice( title, -1 );
}

void CChar::SendOff()
{

}

int CChar::level2skill(int lv)
{
	//�ȼ����������ƶ��ձ�
	//1,����5��ÿ��+4
	if(lv < 5) return (lv + 1) * 4;
	//2,����25��ÿ��+3
	if(lv < 25) return 24 + (lv - 5) * 3;
	//3,֮��ÿ��+3.5
	return 84 + (lv - 25) * 7 / 2;	
}

//�ȼ�������ֵ�����ԣ����ܵ���ձ�
MYLONG CChar::Level2Exp(int lv)
{
	static unsigned long level_exp[176] =
	{
		0,						//1			
		100,					//2
		350,					//3
		750,					//4
		1300,					//5		1
		2100,					//6		2
		3300,					//7		3
		4600,					//8		4
		6000,					//9		5
		7500,					//10		6
		9100,					//11		7
		10800,					//12		8
		12600,					//13		9
		14500,					//14		10
		16500,					//15		11
		18700,					//16		12
		21100,					//17		13
		23700,					//18		14
		26500,					//19		15		
		29500,					//20		16		
		32800,					//21		17		
		36400,					//22		18
		40300,					//23		19		
		44500,					//24		20
		49100,					//25		21		
		54300,					//26		22
		60000,					//27		23		
		66300,					//28		24
		73300,					//29		25		84
		81000,					//30		26
		89900,					//31		27		91
		100000,			//32		28
		112400,			//33		29				98
		125900,			//34		30
		140400,			//35		31				105
		156000,			//36		32
		172800,			//37		33				122
		190600,			//38		34
		209700,			//39		35				129
		229900,			//40		36
		251500,			//41		37				136
		274400,			//42		38
		298500,			//43		39				143
		324100,			//44		40
		351100,			//45		41				150
		379600,			//46		42
		409600,			//47		43				157
		441000,			//48		44
		474100,			//49		45				164
		508800,			//50		46
		545100,			//51		47				171
		583200,			//52		48
		622900,			//53		49				178
		664400,			//54		50
		707700,			//55		51				185
		752900,			//56		52
		800000,			//57		53				
		848900,			//58		54
		899800,			//59		55
		952800,			//60		56
		1007700,		//61		57
		1064800,		//62		58
		1123900,		//63		59
		1185200,		//64		60
		1248700,		//65		61
		1314400,		//66		62
		1382400,		//67		63
		1452600,		//68		64
		1525200,		//69		65
		1600300,		//70		66
		1677700,		//71		67
		1757600,		//72		68
		1839900,		//73		69
		1924800,		//74		70
		2012300,		//75
		2102400,		//76
		2195200,		//77
		2290600,		//78
		2388700,		//288
		2489700,		//292
		2593400,		//296
		2700000,		//300
		2809400,		//304
		2921800,		//308
		3037100,		//312
		3155400,		//316
		3276800,		//320
		3401200,		//324
		3528700,		//328
		3659400,		//332
		3793300,		//336
		3930400,		//340
		4070700,		//344
		4214400,		//348
		4361400,		//352
		4511800,		//356
		4665600,		//360
		4822800,		//364
		4983600,		//368
		5147800,		//372
		5315700,		//376
		5487200,		//380
		5662300,		//384
		5841100,		//388
		6023600,		//392
		6209900,		//396
		6400000,		//400
		6593900,		//404
		6791700,		//408
		6993400,		//412
		7199100,		//416
		7408800,		//420
		7622500,		//424
		7840200,		//428
		8062100,		//432
		8288100,		//436
		8518400,		//440
		8752800,		//444
		8991500,		//448
		9234500,		//452
		9481800,		//456
		9733600,		//460
		9989700,		//464
		10250300,		//468
		10515400,		//472
		10785000,		//476
		11059200,		//480
		11337900,		//484
		11621400,		//488
		11909500,		//492
		12202300,		//496
		12500000,		//500
		12802400,		//504
		13109600,		//508
		13421700,		//512
		13738800,		//516
		14060800,		//520
		14387700,		//524
		14719700,		//528
		15056800,		//532
		15399000,		//536
		15746400,		//540
		16098900,		//544
		16456600,		//548
		16819600,		//552
		17187900,		//556
		17561600,		//560
		17940600,		//564
		18325000,		//568
		18714900,		//572
		19110200,		//576
		19511200,		//580
		19917600,		//584
		20329700,		//588
		20747400,		//592
		21170800,		//596
		21600000,		//600
		22215798,
		23204790,
		24940174, 
		28168338, 
		34382063, 
		46566912, 
		70694007, 
		118705595, 
		190625560, 
		286477811, 
		406286280, 
		550074923, 
		717867721, 
		909688677, 
		1125561819, 
		1365511201, 
		1629560897, 
		1917735009, 
/*
		2230057661, 	
		2566553001,
		2927245202, 
		3312158461, 
		3721316999, 
		4154745062, 
		4612466918, 
		5094506861, 
		5600889211, 
		6131638308, 
		6686778520, 
		7266334238, 
		7870329877, 
		8498789878, 
		9151738705, 
		9829200846, 
		10531200815, 
		11257763149, 
		12008912412, 
		12784673189, 
		13585070093, 
		14410127760, 
		15259870850, 
		16134324049, 
		17033512067, 
*/		
	};

/*
	long ratio = 1000;
	long exp = 0;
	int level = 0;
	
	if(! lv) return 0;

	while(level < lv)
	{
		exp += ratio;
		level++;
		exp = skill * skill * skill /1000 * 100;
		TRACE("%ld,		//%ld\n", exp, skill);
		ratio = ratio * 110 / 10000 * 100;
	}

	return exp;
	*/

	if(lv < 1 ) return 0;
	
	//if( lv >= 158 ) return 21600000 + lv * 1000000;
	if( lv >= 176 ) return 1917735009 + lv * 100000000;
	return level_exp[lv - 1];
}

//���ݾ���ֵ����ȼ�
int CChar::exp2level(MYLONG exp)
{
	int lv = 0;
	while( Level2Exp(lv) <= exp)
		lv++;

	return lv - 1;
}

void CChar::assign_apprentice(const char * title, int privs)
{
	CMapping * family;
	char msg[255], tmp[255];

	if(!( family = querymap("family")) ) return;

	family->set("title", title);
	family->set("privs", privs);

    if( Query(IS_USER) || !querystr("title")[0] )
	{
		if( family->query("generation") == 1 )
		{
			snprintf(msg, 255, "%s��ɽ��ʦ", family->querystr("family_name"));
		}
		else
		{
			snprintf(msg, 255, "%s��%s��%s", family->querystr("family_name"),
				chinese_number(family->query("generation"), tmp), family->querystr("title"));
		}

		set_title(msg);
	}
}

void CChar::set_title(const char * title)
{
	set("title", title);
	UpdateMe();
}

int CChar::prevent_learn(CChar *me, const char * skill)
{
	int betrayer;

	if( (betrayer = me->query("betrayer")) )
	{
		if( me->query_skill(skill, 1) >= query_skill(skill, 1) - betrayer * 20 ) 
		{
			message_vision("$N��ɫ���ƺ���$n����ʮ�����Σ�Ҳ��������$p��ǰ����ʦ�ŵ����� ...��", this, me);
			say("�� .... ʦ���ܽ���Ķ����ˣ����������Լ����ɡ�", me);
			SendMenu(me);
			return 1;
		}
	}

	if( ! me->is_apprentice_of(this)
		&&	this->query_skill(skill, 1) <= me->query_skill(skill, 1) * 3 ) 
	{
		say(g_Channel.do_emote(this, 0, "hmm", 1), me);
		say(g_Channel.do_emote(this, me, "pat", 1), me);
		say("��Ȼ���������µĵ��ӣ����ǲ����ҵĵմ����� ....", me);
		say("��ֻ�ܽ�����Щ��ǳ�ı��Ź��������Ļ���ȥ����ʦ��ѧ�ɡ�", me);
		SendMenu(me);
		return 1;
	}

	return 0;
}

int CChar::update_condition()
{
	CMapping * conditions;
	CVector v;
	CCondition * cnd;
	int update_flag = 0, flag;

	conditions = querymap("condition");
	if( ! conditions ) return 0;

	conditions->keys(v);
	
	for( int i = 0; i < v.count(); i++)
	{
		cnd = load_condition(v[i]);

		flag = cnd->update_condition(this, (* conditions)[v[i]]);
		
		if( !( flag & CND_CONTINUE ) )	//ɾ������Ŀ
		{
			conditions->del(v[i]);
		}
				
		update_flag |= flag;
   }

	//���Conditions�Ƿ�����
	if(! conditions->GetCount())
		del("condition");
   
   return update_flag;
}

void CChar::apply_condition(const char * cnd, LONG duration)
{
	char key[80];
	
	snprintf(key, 80, "condition/%s", cnd);
	
	if(duration)
	{
		if(! query_condition(cnd))
		{
			CCondition * condi = load_condition(cnd);
			condi->init(this);			
		}

		set(key, duration);
	}
	else
		del(key);
}

void CChar::map_skill(const char * skill, const char * mapped_to)
{
	if( ! mapped_to)
	{
		skill_map.del(skill);
		return;
	}

	if(! load_skill(skill))
	{
		return;
	}

	if( ! skills.query(mapped_to) )
		return;
   
	skill_map.set(skill, mapped_to);
}

void CChar::prepare_skill(const char * skill, const char * mapped_to)
{
	if( !mapped_to ) 
	{
		skill_prepare.del(skill);
        return;
    }

    if(! load_skill(skill))
	{
		return;
	}

    if( ! skills.query(mapped_to) )
        return;

    skill_prepare.set(skill, mapped_to);
}

const char * CChar::query_skill_mapped(const char * skill)
{
	return skill_map.querystr(skill);	
}

const char * CChar::query_skill_prepared(const char * skill)
{
	return skill_prepare.querystr(skill);
}

int CChar::query_skill(const char * skill, int raw)
{
	if( !raw ) 
	{
		int s;
		char key[80];
		
		snprintf(key, 80, "apply/%s", skill);
   
		s = query_temp(key);
		s += skills.query(skill) / 2;

		const char * key2 = skill_map.querystr(skill);
		if(key2[0])
			s += skills.query(key2);

		return s;
	}
  
	return skills.query(skill);
}

CMapping * CChar::query_skill_map()
{
	return & skill_map;
}

CMapping * CChar::query_skill_prepare()
{
	return & skill_prepare;
}

int CChar::skill_death_penalty()
{
//	if( wizardp(this) ) return 0;
	int i;
	CVector v;
	skills.keys(v);

	int lvl = query("level");
	int all_skill_lost = 0;

	//������ϵļ����Ƿ񳬹��ȼ�����
	for(i = 0; i < v.count(); i++)
	{
		const char * key = v[i];
		CSkill * sk = load_skill(key);
		if( strcmp(sk->type(), "martial") == 0			//���ڵȼ�����ȫ�����ܵ�һ��.
			&&	skills.query(key) > level2skill(lvl) ) 
		{
			all_skill_lost = 1;
			break;
		}
	}

	if(querymap("freedom"))
		all_skill_lost = 1;

	if(! all_skill_lost)
	{
		//ֻ����߻���ͼ��ܵ�һ����
		const char * skill_h = 0, * skill_l = 0;
		LONG level_h = 0, level_l = 0;

		for(i = 0; i < v.count(); i++)
		{
			if(! level_h)
			{
				level_l = level_h = skills[v[i]];
				skill_l = skill_h = v[i];
			}
			
			if( level_h < skills[v[i]])
			{
				level_h = skills[v[i]];
				skill_h = v[i];
			}

			if( level_l > skills[v[i]])
			{
				level_l = skills[v[i]];
				skill_l = v[i];
			}
		}
		
		if(! random(3)) 
		{
			skill_h = skill_l;
			level_h = level_l;
		}

		if(skill_h)
		{
			if( learned[skill_h] > (level_h + 1) * (level_h + 1) / 2 )
				learned.del(skill_h);
			else
			{
				level_h--;

				if(level_h < 1)	
				{
					skills.del(skill_h);
					learned.del(skill_h);
				}
				else
					skills.set(skill_h, level_h);		
				
			}
			
			skill_map.clear();
			FlushMySkill(this);

			set("death/skill_name", skill_h);
		}
		
		if(Query(IS_USER))
		{
			time_t t;
			time(&t);

			output_error("death:[%s] %s lost skill %s to %ld.",	ctime(&t), id(1), skill_h ? skill_h : "��", level_h);
		}
		
	}
	else	//ȫ���书��һ��
	{
		for(i = 0; i < v.count(); i++)
		{
			const char * sk = v[i];
			int level = skills[sk];

			if( learned[sk] > (level + 1) * (level + 1) / 2 )
				learned.del(sk);
			else
			{
				level--;

				if(level < 1)	
				{
					skills.del(sk);
					learned.del(sk);
				}
				else
					skills.set(sk, level);					
			}
			
			skill_map.clear();
			FlushMySkill(this);

			set("death/skill_name", "all");	
		}

		if(Query(IS_USER))
		{
			time_t t;
			time(&t);

			output_error("death:[%s] %s lost skill all 1 level!", ctime(&t), id(1));
		}
	}

	return 1;
}

int CChar::skill_death_recover()
{
	//CMapping::ITERATOR_INT p;
	LONG amount;
	
	const char * skill_h = _M.querystr("death/skill_name");

	if(DIFFERSTR(skill_h, "all"))
	{
		LONG level_h = query_skill(skill_h, 1);

		if( ! learned.query(skill_h) )
		{
			amount = (level_h + 1) * (level_h + 1) * 3 / 4;
			learned.set(skill_h, amount);
		}
		else
		{
			skills.set(skill_h, level_h + 1);		
		}
	}
	else	//ȫ�ָ�һ��
	{
		CVector v;
		skills.keys(v);

		for(int i=0; i<v.count(); i++)
		{
			const char * sk = v[i];
			int level = skills[sk];
			if( ! learned.query(sk) )
			{
				amount = (level + 1) * (level + 1) * 3 / 4;
				learned.set(sk, amount);
			}
			else
			{
				skills.set(sk, level + 1);		
			}
		}
	}
	
	FlushMySkill(this);

	return 1;
}

void CChar::improve_skill(const char * skill, int amount, int weak_mode)
{
//	int spi;
	CSkill * sk;
	char msg[255];

	if(! skill[0]) return;

	sk = load_skill(skill);
	if(sk->query("fail_ob"))
		return;

	if( ! weak_mode || ! userp(this)) 
	{
		if( skills.undefinedp(skill) ) skills.set(skill, 0l);
	}

	learned.add(skill, amount);
	
	if(( ! weak_mode || ! userp(this))	
		&&  learned.query(skill) > (skills.query(skill) + 1) * (skills.query(skill) + 1))
	{
		skills.add(skill, 1);
		learned.set(skill, 0l);
		tell_object(this , snprintf(msg, 255, "$YEL��ġ�%s�������ˣ�", sk->name(1)) );
		
		sk->skill_improved(this);

		//֪ͨ
		FlushMySkill(this);
	}
}

CMapping * CChar::query_skills()
{
	return & skills;
}

CMapping * CChar::query_learned()
{
	return & learned;
}

int CChar::is_busy()
{
	return m_Busy || m_nBusy; 
}

int CChar::is_fighting(CContainer * enemy)
{
	if(! query_temp("fight/is_fighting"))
		return 0;

	if(enemy)
	{
		if(enemy->environment() != environment())
			return 0;
		if( enemy->query_temp("fight/is_fighting") && enemy->query_temp("fight/fight_team") != query_temp("fight/fight_team"))
			return 1;

		return 0;
	}

	return 1;
}


void CChar::clear_condition()
{
	del("condition");
}

LONG CChar::query_condition(const char * cnd)
{
	char key[40];
	
	snprintf(key, 40, "condition/%s", cnd);
	return _M.query(key);
}

int CChar::is_killing(CChar *ob)
{
	char id[20];
	return (m_Killers.find(snprintf(id, 20, "%ld", ob->object_id())) != m_Killers.end());
}

void CChar::kill_ob(CChar *ob)
{
	set_killer(ob);	
	fight_ob(ob);
}

void CChar::fight_ob(CChar *ob)
{
	cmd_hit_ob(ob, "");
}

void CChar::init(CChar *me)
{
	const char * vendetta_mark;

	if(	is_fighting()
		||	! Query(IS_LIVING)
		||	! me 
		||	! me->Query(IS_LIVING)
		||	me->query_temp("net_dead") )
		return;

	// Now start check the auto fight cases.
	vendetta_mark = querystr("vendetta_mark");
	char mark[80];
	
	snprintf(mark, 80, "vendetta/%s", vendetta_mark);

	if( userp(me) && is_killing(me) ) 
	{
		g_Combatd.auto_fight(this, me, "hatred");
		return;
	} 
	else if( vendetta_mark[0] &&		
		me->query(mark)) 
	{
		g_Combatd.auto_fight(this, me, "vendetta");
		return;
	}
	else if( userp(me) && EQUALSTR(querystr("attitude"), "aggressive" ) )
	{
		g_Combatd.auto_fight(this, me, "aggressive");
		return;
	} 
}

//���ͽ�ɫ״̬
//exe-���� dis-disable״̬ net-���� poi-�ж� idl-����
void CChar::SendState(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "&C=%d&T=%ld&", STATE, object_id());
	GetStateMsg(msg);

	if(! me)
		MessageVision(this, "command", msg, this);
	
	char str[80];
	snprintf(str, 80, "hp=%ld&mp=%ld&eh=%ld&mm=%ld&", query("hp"), query("mp"), query("eff_hp"), query("max_mp"));
	strcat(msg, str);

	//���㹥��
	const char * skill_type = "unarmed";
	CContainer * weapon;
	LONG ap, dp, pp;

	CVector v;
	CMapping * prepare = query_skill_prepare();
	prepare->keys(v);
		
	//1, ѡ�����ֶ��������������ļ��ܡ�
	if((weapon = query_weapon()))
		skill_type = weapon->querystr("skill_type");
	else if ( v.count() == 0)	skill_type = "unarmed";
	else skill_type = v[0];	

	ap = (LONG)g_Combatd.Skill_Power(this, skill_type, SKILL_USAGE_ATTACK);
	pp = (LONG)g_Combatd.Skill_Power(this, skill_type, SKILL_USAGE_DEFENSE);
	dp = (LONG)g_Combatd.Skill_Power(this, "dodge", SKILL_USAGE_DEFENSE);

	snprintf(str, 80, "att=%ld&def=%ld&",
		ap/100 + 1, 
		//who->query_temp("apply/damage"),
           (dp + (weapon? pp: (pp/10)))/100 + 1);
		//who->query_temp("apply/armor"));
	strcat(msg, str);
	
	//����
	if(query("mp_factor"))
	{
		snprintf(str, 80, "jl=%ld&", query("mp_factor"));
		strcat(msg, str);
	}

	SendCommand(msg, 2);
}

void CChar::GetStateMsg(char *msg)
{
	char str[40];
	const char * disable;
	
	//��ս����Ϣ��������
	if(is_fighting())
	{
		if(query_temp("fight/fight_team"))
			strcat(msg, "tea=1&");
		if(query_temp("fight/ap"))
		{
			snprintf(str, 40, "ap=%d&", query_temp("fight/ap"));
			strcat(msg, str);
		}
	}
	else
		strcat(msg, "tea=-1&");

	int max_hp = query("max_hp");
	if(max_hp)
	{
		snprintf(str, 40, "sta=%ld&", query("hp") * 100 / max_hp);
		strcat(msg, str);
	}
	
	disable = querystr_temp("disabled");
	if(disable[0])
		strcat(msg, snprintf(str, 40, "dis=%s&", disable) );
	
	if(query_temp("pending/exercising"))	//�ڴ���
		strcat(msg, "exe=1&");
	
	if(query_temp("net_dead"))	//������
		strcat(msg, "net=1&");

	//����Ƿ��ж�
	CMapping * conditions = querymap("condition");
		
	if(conditions)
	{
		CVector v;

		conditions->keys(v);
		for( int i=0; i<v.count(); i++)
		{
			if(strstr(v[i], "poison"))
			{
				strcat(msg, "poi=1&");
				break;
			}
		}
	}

	//����Ƿ񷢴���ս���в�������
	if(Query(IS_USER) && ((CUser *)this)->query_idle() > 180
		&& ! is_fighting())
		strcat(msg, "idl=1&");

}

int CChar::recognize_apprentice(CChar *me)
{
	return 0;
}

//��ѯ�ü�����������Ҫ�ĵ���
LONG CChar::skill_need_points(const char * skill)
{
	LONG need_pt = (skills.query(skill) + 1) * (skills.query(skill) + 1) -	learned.query(skill);

	//�ٸ����ϼ�������������
	//20�������ϣ�ÿ��һ��Ŀ����Ҫ����ƽʱ��10%�ľ���
	if( skills.GetCount() > 20 )
		need_pt = need_pt * (10 + skills.GetCount() - 20) / 10;
	
	if(need_pt < 1) return 1;

	return need_pt;
}

//���ؿ��þ����
LONG CChar::query_valid_exp()
{
	LONG exp = CChar::Level2Exp(query("level"));
	LONG need_exp = query("combat_exp") - exp - query("sk_exp");
	
	return need_exp;
}

void CChar::set_killer(CChar *ob)
{
	char msg[80];

	if( m_Killers.find(ob->querystr("id")) == m_Killers.end() )
		m_Killers.append(ob->querystr("id"));

	tell_object(ob, snprintf(msg, 80, "$RED������%s��ɱ���㣡", name()));
}

void CChar::remove_killer(CChar *ob)
{
	m_Killers.remove(ob->querystr("id"));
}

void CChar::remove_all_killer()
{
	m_Killers.clear();
}

LONG CChar::query_combat_exp()
{
	return CChar::Level2Exp(query("level"));
}

CMapping * CChar::query_action()
{
	static CMapping m_action;
	
	static char human_combat_action[5][80] = {
	{ "$N��ȭ����$n��$l",},
	{ "$N��$n��$lһץ",},
	{"$N��$n��$l�ݺݵ�����һ��",},
	{"$N����ȭͷ��$n��$l��ȥ",},
	{"$N��׼$n��$l�����ӳ�һȭ",},
	};
	
	if(EQUALSTR(querystr("race"), "����"))
	{
		m_action.set("action", human_combat_action[random(5)]);
		m_action.set("damage", 0l);
		return &m_action;
	}

	static struct
	{
		char verb[10];
		char action[80];
		int		damage;
	}beast_combat_action[5] = {
		{"hoof", "$N�ú�����$n��$l����һ��", 100,},
		{"bite", "$N������������$n��$l�ݺݵ�һҧ",20,},
		{"claw", "$N��צ����$n��$lһץ", 0},
		{"poke", "$N������$n��$lһ��", 30,},
		{"knock", "$N��ͷ��$n��$l����һײ", 100,},
	};
	string verb;
	CVector * v;

	if(EQUALSTR(querystr("race"), "Ұ��"))
	{
		if(! (v = queryvec("verbs"))) 
		{
			m_action.set("action", "$N����$n��$l��");
			m_action.set("damage", 0l);
			return &m_action;
		}

		verb = (* v)[random(v->count())];
		for(int i=0; i<5; i++)
			if(verb == beast_combat_action[i].verb)
			{
				m_action.set("action", beast_combat_action[i].action);
				m_action.set("damage", beast_combat_action[i].damage);
				return &m_action;
			}
	};

	m_action.set("action", "$N����$n��$l��");
	m_action.set("damage", 0l);
	//ȱʡaction
	return &m_action;
}

//���Խ���ʱ���С�
void CChar::is_defeated(CChar * winner, CChar * failer)
{
	static char winner_msg[11][80]=
	{
		"\n$N������Ц������˵���������ˣ�\n",
        "\n$N˫��һ����Ц��˵����֪���ҵ������˰ɣ�\n",
        "\n$Nʤ�����У�Ц����ʤ���˱��ҳ��£��������⡣\n",
        "\n$n������˼�����˵�����������շ�����\n",
		"\n$n���һ�ݣ��޺޵�˵�������ӱ���ʮ�겻��\n",
		"\n$N������Ц��˵���������ˣ�\n",
        "\n$N˫��һ����Ц��˵�������ã�\n",
        "\n$Nʤ�����У����Ծ�����ߣ�Ц�������ã�\n",
        "\n$n��ɫ΢�䣬˵��������������\n",
        "\n$n������˼�����˵�����ⳡ�����������ˣ�����������\n",
        "\n$n���һ�ݣ�������Ҿ˵�����������ղ�������Ȼ������\n",
	};

	if(winner == this)
	{
		CChar * obj = find_npc(winner->query_temp("biwu/npc"));

		winner->delete_temp("biwu/npc");
		failer->delete_temp("biwu/npc");

		if(obj)
			obj->is_defeated(winner, failer);

		message_vision(winner_msg[random(11)], winner, failer);
	}
}

void CChar::set_leader(CChar *me)
{
	if( me == this )
		output_error("set_leader: Cannot set this_object() as leader.");

	m_Leader = me;
}


CChar * CChar::query_leader()
{
	return m_Leader;
}

int CChar::follow_me(CChar * me, char * dir)
{
	char msg[80];
	if( !living(this) || me == this ) return 0;

	if( me == m_Leader
		||	(query("pursuer") && is_killing(me))) 
	{
		return command(snprintf(msg, 80, "go 0 %s", dir));		
	}

	return 0;
}

void CChar::remove_faint(CContainer *me, LONG param1, LONG param2)
{
	me->delete_temp("last_fainted_from");
}

int CChar::query_per()
{
	return query("per") + query_temp("apply/per");
}

void CChar::relay_emote(CChar *me, string verb)
{

}

void CChar::relay_say(CChar *me, char *msg)
{

}

//�ͷ�ԭ��ʦ������ͽ��¼
void CChar::release_master()
{
	char msg[80];

	if(! query("family/user")) return;	//�����ʦ��,����Ҫ�޸�

	const char * master = _M.querystr("family/master_id");
	CMapping * ptr = g_Channel.query_recruit(master);
	if(! ptr) return;

	g_Channel.update_recruit(master, id(1), name(1), 
		ptr->query(snprintf(msg, 80, "%s/exp", id(1))), 0);	
}

//���㵱ǰͽ����Ŀ
int CChar::recruit_num()
{
	int count = 0;
	CMapping * ptr = g_Channel.query_recruit(id(1));
	
	if(ptr)
	{
		CVector v;

		ptr->keys(v);

		for(int i=0; i<v.count(); i++)
		{
			CMapping * m = ptr->querymap(v[i]);
			count += m->query("apprentice");
		}
	}

	return count;
}

const char * CChar::inventory_look(CContainer * obj, int flag)
{
	static char str[80];

	str[0] = 0;
    if( obj->query("equipped") )
         snprintf(str, 80, "%s", obj->name());
    else if(flag)
	{
		LONG amount = obj->Query_Amount();
		if( amount > 1)
			snprintf(str, 80, "����%ld��%s", amount, obj->name());
		else
			snprintf(str, 80, "%s", obj->name());
	}

    return str;
}

int CChar::do_look(CChar *me)
{
	char msg[255], str[40];
	char ability_evaluate[15][20] = 
	{
			"����һ��", 
			"��ͨƤë",
			"��������",
			"����С��",
			"�������",
			"�������",
			"����似",
			"�����뻯",
			"�Ƿ��켫",
			"һ����ʦ",
			"��ɲ�",
			"��ɲ�",
			"��ɲ�",
			"��ɲ�",
			"ǰ�޹��ˣ���������",
	};
	
	int per = query_per();
	if( ! per ) per= random(20);

	char pro[5]; 
	
	strcpy(pro, "��");
	if( me != this )
	{
		tell_object(this, snprintf(msg, 255, "%s�������㿴����֪����Щʲô���⡣", me->name()));
		strcpy(pro, gender_pronoun(querystr("gender")));
	}

	say(snprintf(msg, 255, "%s %s", Short(), Long()), me);
	
	char resident[40];

	resident[0] = 0;
	if( EQUALSTR(querystr("race"), "����") && query("age"))
	{       
        if(querystr("resident")[0])
			snprintf(resident, 40, "%s������������%s��ʿ��", pro, querystr("resident"));
		
	} 
		
	CMapping * skl = query_skills();
	int skills = 0;

	if(skl->GetCount())
	{
		CVector v;

		skl->keys(v);
		for(int i=0; i<v.count(); i++)
			skills += (* skl)[v[i]];

		skills = skills / (10 * skl->GetCount());
		skills += 3 - random(6);
	}

	if(skills<0)	skills=0;
	if( skills >= 15 )	skills = 14;

	char family_des[80];

	family_des[0] = 0;
	int gen = query("family/generation");
	int mygen = me->query("family/generation");

	if( this != me
		&&  me->querymap("family") 
		&&  EQUALSTR(querystr("family/family_name"), me->querystr("family/family_name")) )
	{
        if( gen == mygen ) 
		{
			if( EQUALSTR(querystr("gender"), "����") ||
					EQUALSTR(querystr("gender"), "����")) 
			{
				snprintf(family_des, 80, "�����%s%s��",
					EQUALSTR(querystr("family/master_id"), me->querystr("family/master_id")) ? "" : "ͬ��",
					query("enter_time") > me->query("enter_time") ? "ʦ��": "ʦ��");
			}
			else
			{
				snprintf(family_des, 80, "�����%s%s��",
					EQUALSTR(querystr("family/master_id"), me->querystr("family/master_id")) ? "" : "ͬ��",
					query("enter_time") > me->query("enter_time") ? "ʦ��": "ʦ��");
			}
		}
		else if( gen < mygen )
		{
			if( EQUALSTR(me->querystr("family/master_id"), querystr("id") ))
				snprintf(family_des, 80, "�����ʦ����");
			else if( gen - mygen > 1 )
				strcpy(family_des, "�����ͬ�ų�����");
			else if( query("family/enter_time") < me->query("family/enter_time") )
				strcpy(family_des, "�����ʦ����");
			else
				strcpy(family_des, "�����ʦ�塣");
		} 
		else
		{
			if( gen - mygen > 1 )
				strcpy(family_des, "�����ͬ������");
			else if( EQUALSTR(querystr("family/master_id"), me->querystr("id") ))
				strcpy(family_des, "����ĵ��ӡ�");
			else
				strcpy(family_des, "�����ʦֶ��");
		}
	}
	
	char couple_des[80];

	couple_des[0] = 0;
	if( this != me
		&&  querymap("couple") 
		&&  EQUALSTR(querystr("couple/id"), me->id(1) ))
	{
		snprintf(couple_des, 80, "%s�����%s��", pro, me->querystr("couple/gender"));
	}

	char eff_msg[80];

	eff_msg[0] = 0;
	if( query("max_hp"))
	{
		snprintf(eff_msg, 80, "%s%s", pro, g_Combatd.eff_status_msg(query("eff_hp") * 100 / query("max_hp")) );
	}

	
	if(DIFFERSTR(querystr("race"), "Ұ��"))
	{
		say(snprintf(msg, 255, 
			"%s������Լ%s���ꡣ%s%s%s%s�书������%s��%s%s%s%s", 
			pro, chinese_number(query("age") / 10 * 10, str),
			resident,
			wizardp(this) ? "����ʦ��" : "",
			(query("age") > 15 || wizardp(me)) ? query_waimao( querystr("gender"), per) : "",
			pro, ability_evaluate[skills],
			family_des[0] ? pro : "", family_des,
			couple_des,
			eff_msg),
			me);
	}
	
		//���ϴ�����Ʒ
		DTItemList * list = Get_ItemList();

		if(list->GetCount())
		{
			CContainer * item;
			POSITION pos;
			int flag = Query(IS_CORPSE);
			if( me->query("grant") >= 70 && me != this) flag = 1;
							
			pos = list->GetHeadPosition();
			while(pos)
			{
				item = list->GetNext(pos);
				AddMenuItem(inventory_look(item, flag), 
					flag ? snprintf(msg, 80, "$0get %ld from $1", item->object_id()) : "", me);
			}
			
			AddMenuItem("�����۲�", "", me);
		}

		LONG me_shen = me->query("repute");
		LONG obj_shen = query("repute");

       	if( this != me && living(this)
			&& ( (me_shen < 0 && obj_shen > 0) 
				|| (me_shen > 0 && obj_shen < 0))
			&& ( (me_shen - obj_shen > query("mp") * 20)
				|| ( obj_shen - me_shen > query("mp") * 20)) )
		{
			tell_object(me, snprintf(msg, 255, "%sͻȻת��ͷ������һ�ۡ�", name()));
				
			if(query("age") > 15 && me->query("age") > 15 
				&& ( me->query("per") < query("per") 
				 || me->query("per") < 20) )
			{
				//���ӹ۲�����ս����Ϊ����PK�ߵ�����
				me->set_temp("pending/PK", current_time);
				g_Combatd.auto_fight(this, me, "berserk");
			}
		}

	return 0;
}

int CChar::query_grant()
{
	return query("grant");
}

//���ض��� Designed For Lingering Tale lanwood 2001-03-21
CContainer * CChar::query_shield()
{
	LONG weapon = Query_Equip(WIELD_LEFT_HAND);	//����������
	if(! weapon) return 0;

	CContainer * ob = Present(weapon);
	if(!ob || DIFFERSTR(ob->querystr("armor_type"), "shield") ) return 0;

	return ob;
}

int CChar::is_loading()
{
	return query_temp("client/loading");
}

//Ϊ���μǶ����� 2001-03-23
int CChar::query_kar()
{
	return query("kar") + query_temp("apply/kar");
}

//ΪLT���� 2001-03-27
LONG CChar::query_apply(const char * attr)
{
	char key[80];
	
	snprintf(key, 80, "apply/%s", attr);
	return query(attr) + query_temp(key);
}

//����û��Ƿ�ܾ�������Ƶ����Ϣ
int CChar::refuse_channel(const char *channel)
{
	char msg[80];
	return query_temp(snprintf(msg, 80, "refuse/%s", channel));
}

//ѧϰϵ��������learn�ļ���
int CChar::learn_bonus()
{
	LONG pt = query("level") * query_int() / 50;
	if(pt <= 0) return 1;
	if(pt <= 30) return pt;
	if(pt <= 50) return 30 + (pt - 30) / 2;
	if(pt <= 80) return 45 + (pt - 50) / 3;
	return 55 + (pt - 80) / 5;
}

//ɱ��ĳ���ʱ����
void CChar::finish_kill(CChar *me)
{

}

int CChar::query_unarmed()
{
	int improve = query_skill("unarmed", 1);

	if ( query_skill("unarmed",1)
	  || query_skill("strike", 1)
	  || query_skill("finger", 1)
	  || query_skill("cuff", 1)
	  || query_skill("hand", 1)
	  || query_skill("claw", 1))
	{
		if ( query_skill("strike", 1) >= improve )
			improve = query_skill("strike", 1);
		if ( query_skill("finger", 1) >= improve)
			improve = query_skill("finger", 1);
		if ( query_skill("cuff", 1) >= improve)
			improve = query_skill("cuff", 1);
		if ( query_skill("hand", 1) >= improve)
			improve = query_skill("hand", 1);
		if ( query_skill("claw", 1) >= improve)
			improve = query_skill("claw", 1);
	}
	
	return improve;
}

//������ʦ��¼
void CChar::Remove_Betrayer(CChar *me)
{
	int lv = me->query("betrayer");
	me->del("betrayer");
	me->add("erase/betrayer", lv);

	//ȫ���书��lv * 20��
	CMapping * skills = me->query_skills();
	CMapping * learned = me->query_learned();

	lv *= 20;

	CVector v;

	skills->keys(v);
	for(int i=0; i<v.count(); i++)
	{
		learned->del(v[i]);
		me->map_skill(v[i]);
		me->prepare_skill(v[i]);
		if( (* skills)[v[i]] > lv)
			(* skills)[v[i]] -= lv;
		else
			skills->del(v[i]);	
	}

	me->FlushMySkill(me);
	
	output_error("%s��ʦ��������ʦ��¼��ȫ�����ܽ�%ld����", me->name(1), lv);
}

//������ͼ��ܵĵȼ�
int CChar::mini_skill()
{
	CVector v;
	int max_skill = 9999;

	if(! skills.GetCount()) return 0;

	skills.keys(v);

	for(int i=0; i<v.count(); i++)
	{
		int lv = skills[v[i]];
		if(max_skill > lv)
			max_skill = lv;			
	}

	return max_skill;
}

void CChar::FlushMyInfo()
{
	//��ý�ɫ��Ϣ
	char msg[512], str[255];
	static char szAttr[11][20]={"age", "level", "repute", "combat_exp", "hp", "mp", "max_hp", "max_mp",
		"eff_hp", "pks", "mks"};
	static char szA[11][2]={"a", "b", "c", "d", "e", "f", "g", "h", 
		"i", "m", "n"};

	if(! userp(this)) return;
		
	LONG sk_exp = _M.query("combat_exp") / 3 - _M.query("sk_exp");
	LONG valid_exp = query_valid_exp();

	snprintf(msg, 255, "&C=%d&T=%ld&o=%s&p=%s&P=%ld&q=%s&r=%s&s=%s&t=%s&u=%ld&v=%ld&exp=%ld&nex=%ld&sk=%ld&master=%s&", 
		RTNINFO,
		object_id(), id(), name(),
		_M.query("icon"),
		_M.querystr("gender"), _M.querystr("class"), _M.querystr("race"),
		title(),
		query_encumb(),	
		query_max_encumbrance(),
		valid_exp,
		CChar::Level2Exp(_M.query("level") + 1) - CChar::Level2Exp(_M.query("level")),
		sk_exp < valid_exp ? sk_exp : valid_exp,
		_M.querystr("family/master_name"));
	
	//�������
	for(int i=0; i<11; i++)
	{
		snprintf(str, 255, "%s=%ld&", szA[i], _M.query(szAttr[i]));
		strcat(msg, str);
	}

	snprintf(str, 255, "E=%ld&F=%ld&G=%ld&H=%ld&", 
		query_str(), query_con(), query_int(), query_dex());
	strcat(msg, str);


	//���㹥��
	const char * skill_type;
	CContainer * weapon;
	unsigned long ap, dp, pp;

	CVector v;
	CMapping * prepare = query_skill_prepare();
	prepare->keys(v);
		
	//1, ѡ�����ֶ��������������ļ��ܡ�
	if((weapon = query_weapon()))
		skill_type = weapon->querystr("skill_type");
	else if ( v.count() == 0)	skill_type = "unarmed";
	else skill_type = v[0];	

	ap = (unsigned long)g_Combatd.Skill_Power(this, skill_type, SKILL_USAGE_ATTACK);
	pp = (unsigned long)g_Combatd.Skill_Power(this, skill_type, SKILL_USAGE_DEFENSE);
	dp = (unsigned long)g_Combatd.Skill_Power(this, "dodge", SKILL_USAGE_DEFENSE);

	if(ap>4200000000)ap=4200000000;
	if(pp>4200000000)pp=4200000000;
	if(dp>4200000000)dp=4200000000;
	unsigned long att,def;
	att=ap/100 + 1;
	def=dp /100+ (weapon? pp: (pp/10))/100 + 1;
	snprintf(str, 255, "I=%ld&J=%ld&K=%ld&L=%ld&",
		att, 
		query_temp("apply/damage"),
        def, 
		query_temp("apply/armor"));

	strcat(msg, str);
//	output_error(msg);

	SendCommand(msg, 1);
}

void CChar::FlushMyEquip()
{
	DTItemList * list;
	POSITION p;
	CContainer * t;
	int i = 0;
	char str[40], msg[512];

	if(! userp(this)) return;
	
	snprintf(msg, 40, "&C=%d&B=0&T=%ld&", RTNITEM, object_id());
	
	list = &m_ItemList;
	p = list->GetHeadPosition();
	while(p)
	{
		if(i && i % 10 == 0)
		{
			SendCommand(msg, 1);
			snprintf(msg, 40, "&C=%d&B=%ld&T=%ld&", RTNITEM, i, object_id());
		}

		t = list->GetNext(p);
		snprintf(str, 40, "I%d=%ld&", i, t->object_id());
		strcat(msg, str);

		if(t->query("equipped"))	//װ����Ҫ����װ����־
		{
			snprintf(str, 40, "E%d=%ld&", i, t->query("equipped") );
			strcat(msg, str);
		}
		i++;		
	}

	SendCommand(msg, 1);
}

void CChar::FlushMySkill(CChar * me)
{
	const char * map_skill;
	char	str[40], msg[512];
		
	//���ͼ���ָ��: C=RTNSKILL T=Ŀ�� B=1 E=1 ��ʼ������־ S=���� L=���� M=Map���� P=me��������֮�����
	int pt = me->learn_bonus();

	CVector v;

	skills.keys(v);
	int cnt = v.count();
	for(int i = 0; i<cnt; i++)
	{
		const char * skl = v[i];
		LONG need_points =  me->skill_need_points(skl);

		snprintf(msg, 512, "&C=%d&T=%ld&S=%s&L=%d&", RTNSKILL, object_id(),
			skl, skills[skl]);

		if(this == me)	//��who == meʱ�Ŵ���������֮����
		{
			snprintf(str, 40, "P=%ld&", need_points / pt + 1);
			strcat(msg, str);
		}

		map_skill = query_skill_mapped(skl);
		if(map_skill[0])
		{
			snprintf(str, 40, "M=%s&", map_skill);
			strcat(msg, str);
		}

		//��װ�����
		map_skill = query_skill_prepared(skl);
		if(map_skill[0])
		{				
			strcat(msg, "K=1&");
		}
		
		if(i == 0)
			strcat(msg, "B=1&");
		
		if(i == cnt - 1)
			strcat(msg, "E=1&");

		me->SendCommand(msg, 1);
	}
}

int CChar::can_learn(const char *skillname)
{
	if(! skillname[0]) return 0;
	CMapping * m = _M.querymap("forget");
	if(! m) return 1;
	return m->undefinedp(skillname);
}

int CChar::cmd_hit_ob(CChar * who, char *arg)
{
	CContainer * msprite = NULL;
	CContainer * env;
	CFightRoom * room;
	char namestr[21], msg[255];
	int nProtect;

	env = environment();
	if(! env || env->query("no_fight")) 
		return notify_fail("�˵ؽ�ֹս��!");

	if(env != who->environment()) return 0;		//����ͬһ������
		
	if( who->Query(CChar::IS_CORPSE)) return 0;
	if(env->Query(CChar::IS_FIGHTROOM)) 
	{
		room = (CFightRoom *)env;

		//�Ѿ���ս�������ˡ���ûս�����Ҷ�����ս��
		if(is_fighting() )	//����ս��
		{
			if(who->is_fighting()) return 1;

			//����û��ս��,���ּ���ս��
			int team = 1 - query_team();
			if(! room->Can_Join(team, who)) return 1;
			room->Join_Team(who, team);
			tell_room(room, snprintf(msg, 255, "%s����ս��%d.", who->name(), team));			
		}
		else	//��ûս��,�Է�Ҳûս��
		{
			if(! who->is_fighting()) return 1;
		
			int team = 1 - who->query_team();
			if(! room->Can_Join(team, this)) return 1;
			room->Join_Team(this, team);
			tell_room(room, snprintf(msg, 255, "%s����ս��%d.", name(), team));
		}

		return 1;		
	}

	//���ܶԳ�����ɱָ�ֻ�ܶ����ˡ�
//		if(who->Query(CChar::IS_SPRITE)) return 0;
	if(who == this) return 0;						//����ɱ�Լ���
	
	if(who->query_temp("net_dead"))
		return notify_fail("�����������ҷ���������");

	if(is_busy())
		return notify_fail("��������æ�š�");
	
	nProtect = env->query("pk_protect");
	if(nProtect && who->Query(CChar::IS_USER) 
		&& query("level") > nProtect
		&& who->query("level") <= nProtect)
	
		return notify_fail("�ȼ�%d��������ڴ˵���ħ��������", nProtect);
		
	//�ҵ�����
//		msprite = FindSprite(me);
//		esprite = FindSprite(who);

	snprintf(msg, 255, "%s��%sͻȻ����Ϯ��!", name(), who->name());
	MessageVision(this, "chat", msg);

	//who��ֹbusy
	if(who->is_busy())
		who->interrupt_me(this, "kill");

	room = (CFightRoom *)load_item("fight_room");			//����ս������
	strncpy(namestr, name(), 15)[14] = 0; //ȡ�������
	strcat(namestr, "��ս��");
	room->set_name( namestr);

	//----------------------------------------
	//����������Ϣ	1.7�汾 lanwood 2001-03-23
	LONG x = 0, y = 0;
	if(strlen(arg))
	{
		char szY[40];
		analyse_string(arg, szY, 40);
		x = atol(arg);
		y = atol(szY);			
	}

	if(! x || ! y)
	{
		x = query_temp("map/ex");
		y = query_temp("map/ey");
	}
	
	room->set_temp("map/bx", x);
	room->set_temp("map/by", y);
	room->set_temp("map/ex", x);
	room->set_temp("map/ey", y);
	//----------------------------------------

	room->move(env);

	move(room);
	room->Join_Team(this, CFightRoom::FIGHT_TEAM_A);		//����ս��

	who->move(room);
	room->Join_Team(who, CFightRoom::FIGHT_TEAM_B);

	//��¼NK����onwer
	if(! (userp(who)) )
	{
		set_temp("fight/will_nk", who->object_id());
		who->set_temp("fight/owner", object_id());
	}

	//if(nProtect && Query(CChar::IS_USER) && query("level") <= nProtect)	//�����ܱ�����ս��
	//	room->SetFightLevel(query("level"));

	//if(msprite)
	//{
	//	msprite->move(room);
	//	room->Join_Team((CChar *)msprite, CFightRoom::FIGHT_TEAM_A);
	//}

	//if(esprite )
	//{
	//	esprite->move(room);
	//	room->Join_Team((CChar *)esprite, CFightRoom::FIGHT_TEAM_B);
	//}

	//���������������ɵļ���ս����
	if(! userp(who))
	{
		POSITION p;
		DTItemList search;
		const char * bangpai, * mbang, * ebang;
	
		CopyList(&search, env->Get_ItemList());
	
		mbang = querystr("family/family_name");
		ebang = who->querystr("family/family_name");

		p = search.GetHeadPosition();
		while(p)
		{
			msprite = search.GetNext(p);
			if(! msprite->Query(CChar::IS_CHAR)) continue;
			bangpai = msprite->querystr("family/family_name");
			if(bangpai[0])
			{
				if(EQUALSTR(bangpai, ebang))
				{
					snprintf(msg, 255, "join %ld 1", room->object_id());
					if(! userp(msprite))	//NPC��æ
						((CChar *)msprite)->command(msg);
				}
				/*
				else if(bangpai == mbang)
				{
					snprintf(msg, 255, "join %ld 0", room->object_id());
					((CChar *)msprite)->command(msg);
				}
				*/
			}

			if( ((CChar *)msprite)->is_killing(this))
				((CChar *)msprite)->command(snprintf(msg, 255, "join %ld 1", room->object_id()));

			if( ((CChar *)msprite)->is_killing(who))
				((CChar *)msprite)->command(snprintf(msg, 255, "join %ld 0", room->object_id()));
		}

		search.RemoveAll();
	}
	
	room->Begin_Fight(0);		//��ʼս��

	return 1;
}

void CChar::SendTable(const char * table_name, CMapping * table, int total, int page)
{
	char msg[512], tmp[255];	
	CVector v;

	table->keys(v);
	int count = v.count();

	for(int i=0; i<count; i++)
	{		
		CMapping * line = table->querymap(v[i]);
		if(! line) continue;

		snprintf(msg, 255, "&C=%ld&", SENDTABLE);
		if(i == 0)
		{
			if(i == count - 1)
				snprintf(tmp, 255, "st=3&T=%s&R=%ld&P=%d&", table_name, total, page);
			else
				snprintf(tmp, 255, "st=1&T=%s&R=%ld&P=%d&", table_name, total, page);
			strcat(msg, tmp);
		}
		else if(i == count - 1)
				strcat(msg, "st=2&");
		
		CVector v2;
		line->keys(v2);

		for(int j = 0; j<v2.count(); j++)
		{
			snprintf(tmp, 255, "%s=%s&", v2[j], line->querystr(v2[j]));
			strcat(msg, tmp);
		}

		SendCommand(msg);
	}
}

void CChar::attack(CChar * opponent)
{
	g_Combatd.fight(this,  opponent);
}

int CChar::SaveObjectToServer()
{	
#ifdef _SQL_		//���ݿ�

	POSITION p = m_ItemList.GetHeadPosition();
	int idx=0;
			
	while(p)
	{		
		CContainer * obj = m_ItemList.GetNext(p);

		obj->Save();
		
		if(obj->Query_Amount() > 1)
			obj->set("amount", obj->Query_Amount());

		CMapping * savedata = obj->query_entire_dbase();
		const char * ptr = savedata->GetBuffer();

		char msg[1024];
		
		MYSQL_RES *result = NULL;
		//д���ݿ�
		snprintf(msg, 255, "select base_name from t_saveobj where owner=%s and grid = %ld", id(1), idx);
		int nResult = mysql_real_query(&mysql, msg, strlen(msg));
		if(nResult != 0)
		{
			output_error("save_objects: Failed to connect to database: Error: %s", mysql_error(&mysql));
			return 0;
		}

		result = mysql_store_result(&mysql);
		if(result == NULL)
		{
			output_error("saveobject: database fail: store null");		
			return 0;
		}

		int n = mysql_num_rows(result);
		mysql_free_result(result);

		if(n)
			snprintf(msg, 1024, "update t_saveobj set base_name='%s', savedata='%s' where owner = %s and grid = %ld",
				obj->querystr("base_name"), ptr, id(1), idx);
		else
			snprintf(msg, 1024, "insert t_saveobj(owner, grid, base_name, savedata) values(%s, %ld, '%s', '%s')",
				id(1), idx, obj->querystr("base_name"), ptr);

		nResult = mysql_real_query(&mysql, msg, strlen(msg));
		
		if(nResult != 0)
		{
			output_error("save_objects: Failed to connect to database: Error: %s", mysql_error(&mysql));
			return 0;
		}

		idx++;
	}

	set("saveobjects", idx);
	
	return 1;
#else
	return SaveObjectToTemp();
#endif	
}

int CChar::SaveObjectToTemp()
{
	POSITION p = m_ItemList.GetHeadPosition();
	int count = m_ItemList.GetCount();
	int idx = 0;
	FILE * fp;
	char fname[80], base_name[40];
	
	set("saveobjects", count);
	if(! count || count > 99) return 1;

	LONG myid = atol(id(1));

	snprintf(fname, 80, "data/saveobj/%ld/%ld.o", 1 + myid % 25, myid);
	if(! (fp = fopen(fname, "wb")) )	return 0;

	//д���ȱ�
	LONG table[100];
	LONG offset = count * sizeof(LONG);
	fwrite(table, offset, 1, fp);				
	while(p)
	{		
		CContainer * obj = m_ItemList.GetNext(p);
		
		if(obj->Query_Amount() > 1)
			obj->set("amount", obj->Query_Amount());

		CMapping * savedata = obj->query_entire_dbase();
		const char * ptr = savedata->GetBuffer();

		memset(base_name, 0, 40);
		snprintf(base_name, 40, "%s", obj->querystr("base_name"));
		fwrite(base_name, 40, 1, fp);
		fwrite(ptr, strlen(ptr), 1, fp);		
		
		table[idx] = strlen(ptr);
		idx++;
	}

	fclose(fp);

	//д��ƫ�Ʊ�
	if(! (fp = fopen(fname, "r+b")) )	return 0;
	fwrite(table, offset, 1, fp);
	fclose(fp);

	return 1;
}

int CChar::LoadObjectFromServer()
{
#ifdef _SQL_		//���ݿ�汾

	CMapping * savedata;
	char msg[255];
	MYSQL_RES *result = NULL;

	int count = query("saveobjects");
		
	for(int idx=0; idx<count; idx++)
	{

		snprintf(msg, 255, "select base_name, savedata from t_saveobj where owner =%s and grid = %ld", id(1), idx);
		int nResult = mysql_real_query(&mysql, msg, strlen(msg));
		if( nResult != 0)
		{
			output_error("loadobject:query db fail! %s", mysql_error(&mysql));
			return 0;
		}

		result = mysql_store_result(&mysql);
		if(result == NULL)
		{
			output_error("loadobject:database fail: store null");
			return 0;
		}

		int n = mysql_num_rows(result);
		if(n == 0)
		{
			mysql_free_result(result);
			return 0;		
		}

		MYSQL_ROW row;
		row = mysql_fetch_row(result);
		if(row == NULL || row[0] == NULL)
		{
			mysql_free_result(result);
			return 0;
		}
		
		CContainer * obj = load_item(row[0]);
		savedata = obj->query_entire_dbase();	
		savedata->LoadBuffer(row[1]);

		mysql_free_result(result);

		obj->move(this);
		if(obj->query("amount") > 1)
			obj->set_amount(obj->query("amount"));

		obj->del("equipped");	//���װ��״̬
	}

	return 1;

#else
	return LoadObjectFromTemp();
#endif

}

int CChar::LoadObjectFromTemp()
{
	CMapping * savedata;
	FILE * fp;
	char fname[80];

	int count = query("saveobjects");
	LONG myid = atol(id(1));

	if(! count) return 1;

	snprintf(fname, 80, "data/saveobj/%ld/%ld.o", myid % 25 + 1, myid);
	if(! (fp = fopen(fname, "rb")) ) return 0;

	//����ƫ�Ʊ�
	LONG * table = new LONG[count];
	LONG offset = sizeof(LONG) * count;
	fread((char *)table, offset, 1, fp);

	for(int idx=0; idx<count; idx++)
	{
		fread(fname, 40, 1, fp);
		CContainer * obj = load_item(fname);

		int len = table[idx];
		if(len <= 0) continue;

		char * pData = new char[len];
		fread(pData, len, 1, fp);
		
		savedata = obj->query_entire_dbase();	
		savedata->LoadBuffer(pData);
		delete []pData;
	
		obj->move(this);
		if(obj->query("amount") > 1)
			obj->set_amount(obj->query("amount"));

		obj->del("equipped");	//���װ��״̬
	}

	fclose(fp);

	delete []table;

	return 1;
}

int CChar::query_team()
{
	return query_temp("fight/fight_team");
}

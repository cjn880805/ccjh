#include "../server/Room.h"
#include "../server/Npc.h"

#define XiaoYao_BEGIN(room_name)	class room_name : public CRxiaoyao	{	public:	room_name(){};	virtual ~room_name(){};
#define XiaoYao_END		};	

ROOM_BEGIN(CRxiaoyao);

//����ɫ����ʱִ��
//������������һ������ͽ��߳�
//��������ҽ���ʱ���Լ��Ĵ��̵������ڸó������Ա����ߺ��Զ���������
virtual void init(CChar *me)
{
	if(userp(me) )
	{
		CContainer * yinyue_si;
		yinyue_si=me->present("yingyue si");
		if(me->query("xy/renwu6_lost")<3 && !me->query("xy/renwu_lost"))
		{
			if((!me->querymap("xy") || !yinyue_si) && !wizardp(me) )
			{
				me->move(load_room("��ɽ������"));
				return ;
			}
			if(me->querymap("xy") && !me->query("xy/renwu2") && !query("����") && !query("no_autosave"))
			{
				me->set("start_city", querystr("base_name"));
				me->set("xy/save", 1);
			}
			if(!me->query("xy/renwu4"))
			{
				int chance = query("monster_chance");
				if(chance && chance>50)
					chance=50;
				if(chance && random(100) < chance )
				{
					remove_call_out(present_npc);
					call_out(present_npc, 1, me->object_id());
				}
			}
		}
		else
		{
			//�ƽ�Ź�֮��ʧ�����κ�����ʧ��
			//����ʧ��
			message_vision("$NͻȻ����ͷ�����ѣ��к��䣬�����Լ���ɵɵ��վ����ң��ʯ�ݣ��ƺ�ʲô��Ҳû�з�����", me);
			me->move(load_room("��ң��ʯ��"));
			me->set("start_city", START_ROOM);
			
			//��������֮��
			if(yinyue_si)
				destruct(yinyue_si);
			
			//�۳������н�������ң������
			if(me->query_skill("xiaoyao_jianfa",1) )
				me->delete_skill("xiaoyao_jianfa");

			//�������н������貨΢��֮�����貨������
			if(me->query("pro/skill/lingbo_weibu")>me->query("xkd/xy"))
			{
				me->add("pro/skill/lingbo_weibu",-1);
				if(me->query("pro/skill/lingbo_weibu")<=0)
					me->del("pro/skill/lingbo_weibu");
			}

			//�۳������н�����һ����ڤ�񹦻�1000�㾭��
			if(me->query("xy/renwu3_1"))
			{
				if(EQUALSTR(me->querystr("family/family_name"), "��ң��"))
				{
					if(me->query_skill("beiming_shengong",1))
					{
						me->add("pro/skill/beiming_shengong",-1);
						if(me->query("pro/skill/beiming_shengong"))
							me->set_skill("beiming_shengong",300+me->query("pro/skill/beiming_shengong"));
						else
						{
							me->set_skill("beiming_shengong",300);
							me->del("pro/skill/beiming_shengong");
						}
					}
					me->FlushMySkill(me);
				}
				else
					me->add("combat_exp",-1000);
			}
			//�۳������н�����10����������
			if(me->query("xy/renwu4_1"))
			{
				me->add("max_mp",-10);
				me->add("mp",-10);
			}
			//������������еı�־
			me->del("xy");
			me->delete_temp("xy");
		}
	}
}

virtual void setup()
{
	CRoom::setup();
	if(query("����"))
	{
		CContainer * env;
		char msg[255];
		switch(query("����"))
		{
		case 2:
			snprintf(msg, 255,"��ң��%s������17",querystr("����"));
			break;
		case 3:
			snprintf(msg, 255,"��ң��%s������26",querystr("����"));
			break;
		case 4:
			snprintf(msg, 255,"��ң��%s������35",querystr("����"));
			break;
		case 5:
			snprintf(msg, 255,"��ң��%s���Ĳ�44",querystr("����"));
			break;
		case 6:
			snprintf(msg, 255,"��ң��%s�����53",querystr("����"));
			break;
		case 7:
			snprintf(msg, 255,"��ң��%s������62",querystr("����"));
			break;
		}
		env = load_room(msg);
		if(env->query("count")>=6)
		{
			del("����");
			del("λ��");
		}
		else
			env->add("count",1);
	}
}

virtual int do_look(CChar * me)
{
	if(query("����"))
	{
		say("ǽ����һ���������ɵĻ��أ������Ӻ����ܰ⶯��", me);
		AddMenuItem("ѹ��", "$0xia $1", me);
		AddMenuItem("����", "$0shang $1", me);
		SendMenu(me);
	}
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(query("����"))
	{
		if (me->query_temp("xy/renwu4_1")  && me->query("xy/renwu4_3")  )
		{
			char msg[255];
			if(!strcmp(comm, "xia"))
			{
				snprintf(msg, 255,"\n$YEL%s���ĵ�%d��ԶԶ����һ��¡¡������",querystr("����"),query("����"));
				tell_object(me,msg);
				tell_object(me,"�㽫����ѹ�¡�\n");
				snprintf(msg, 255,"xy/ta/%s/%s",querystr("����"),querystr("base_name"));
				if(!me->query_temp(msg)||me->query_temp(msg)!=1)
				{
					me->set_temp(msg,1);
					snprintf(msg, 255,"xy/ta/%s/%d",querystr("����"),query("����"));
					if(query("λ��")==1)
						me->add_temp(msg,1);
					else
					{
						if(me->query_temp(msg))
							me->add_temp(msg,-1);
						else
							me->delete_temp(msg);
					}
				}
				return 1;
			}
			if(!strcmp(comm, "shang"))
			{
				snprintf(msg, 255,"\n$YEL%s���ĵ�%d��ԶԶ����һ��¡¡������",querystr("����"),query("����"));
				tell_object(me,msg);
				tell_object(me,"�㽫����������ȥ��\n");
				snprintf(msg, 255,"xy/ta/%s/%s",querystr("����"),querystr("base_name"));
				if(!me->query_temp(msg)||me->query_temp(msg)!=2)
				{
					me->set_temp(msg,2);
					snprintf(msg, 255,"xy/ta/%s/%d",querystr("����"),query("����"));
					if(query("λ��")==2)
						me->add_temp(msg,1);
					else
					{
						if(me->query_temp(msg))
							me->add_temp(msg,-1);
						else
							me->delete_temp(msg);
					}
				}
				return 1;
			}
		}
	}
	return CRoom::handle_action(comm, me, arg, tar);
}

static void present_npc(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob->Present(param1);
	if(! me) return;
	CNpc * DuWu;
	static char yeshou[8][20]={"animal_bear","animal_eagle","animal_fushe",
		"animal_jinshe","animal_shachong","animal_wubushe","animal_xiezi",
		"animal_yezhu"};
	DuWu = load_npc(yeshou[random(8)]);
	DuWu->move(ob);
	
	message_vision("һ��ɳɳ���죬�ݴ��дܳ���ֻ����,�������$N������", me);
	
	CFightRoom * obj =  (CFightRoom *)load_item("fight_room");	
	obj->set("room_locked", FIGHT_LOCKED);
	obj->set_name("��ң�ȵ�ս��", "fight_room");
	obj->move(ob);

	DuWu->move(obj);
	obj->Join_Team(DuWu, CFightRoom::FIGHT_TEAM_A);
	for(int i=0;i<random(2)+1;i++)
	{
		DuWu = load_npc(yeshou[random(8)]);
		DuWu->move(obj);
		obj->Join_Team(DuWu, CFightRoom::FIGHT_TEAM_A);
	}

	me->move(obj);
	obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
	obj->Begin_Fight(0);
	
}

ROOM_END;




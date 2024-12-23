//house.h
//��ҷ���
//lanwood 2001-03-12

//set_name( "���˾�");
//set("long", "װ�޴ʻ�");
//set("owner", "1010");
//set("second_owner", "2010");
//set("size", 2);
//set("belong", "��ɽ");
//set("pay_time", �ϴνɷ�ʱ��);

int valid_string(const char * msg);

#include "resident.h"
#include "../server/Channel.h"
#include "../server/Npc.h"
#include "../combat/Combatd.h"

ROOM_BEGIN(CRhouse);

void create()	
{
	if(_M.undefinedp("name"))
		set_name("����", "house");	

	set("sleep_room", 1);
	set("area", "house");
	
	set("saveobjects", 1);
	set("max_items", 20);

	CBox * box = Add_Box();
	box->set_name("����", "box");
	box->set("max_items", 14);
	box->set("no_drop_man",1);//�����ﲻ����װ��
		
	make_yongren(querymap("yongren"));
}

void setup()
{
	CDoor * door = add_door("����", querystr("belong"), querystr("name"), "out");
	door->set_name( querystr("belong"));

	if(query("size") < 2)
		set("map", "������1");
	else
		set("map", "������2");

	if(! query("fail_ob"))
		check_pays();
}

static void remove_me(CContainer * ob, LONG param1, LONG param2)
{
	DESTRUCT_OB(ob, "CRhouse::remove_me");
}

void reset()
{
	if(! g_Combatd.query("no_check_house")) 
	{
		if(! Load())	//�˷����Ѿ�������
		{
			call_out(remove_me, 1);
			return;
		}
	}

	CNpc * npc = find_npc(query_temp("yongren"));
	if(! npc) make_yongren(querymap("yongren"));

	//�����Ƿ�Ĺ����
	check_pays();
}

void make_yongren(CMapping * yongren)
{
	CNpc * npc = load_npc("monster_yongren");

	if(yongren)
	{
		npc->set_name( yongren->querystr("name"));
		npc->set("welcome", yongren->querystr("welcome"));
		npc->set("long", yongren->querystr("long"));
		npc->set("welcome_master", yongren->querystr("welcome_master"));
		npc->set("combat_exp", yongren->query("combat_exp"));
	}

	if(! npc->query("combat_exp"))
		npc->set("combat_exp", 20000);

	setup_char(npc);

	npc->move(this);

	set_temp("yongren", npc->object_id());
}

LONG Query(int nAttr)
{
	if(nAttr == CAN_SAVE)
		return 1;
	
	return CRoom::Query(nAttr);
}

int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	CChar * yongren = (CChar *)PresentName("monster_yongren", IS_NPC);
	char msg[255];

	//�κ�ʱ�򶼲�����ʹ��roar
	if(yongren && strcmp(comm, "cast") == 0 && strcmp(arg, "force roar") == 0)
	{
		message_vision("$N��ס$n�����������飿��ȥ����", yongren, me);
		return 1;
	}

	//��������
	if(DIFFERSTR(querystr("owner"), me->id(1))
		&& DIFFERSTR(querystr("second_owner"), me->id(1)))
	{
		if(yongren)
		{
			//�ػ�ʹ��ʱ������ָ�
			if(strcmp(comm, "trans") == 0 || strcmp(comm, "use") ==0)
			{
				CContainer * obj = me->Present(atol(tar));
				if(! obj) return 0;

				if(EQUALSTR(obj->querystr("base_name"), "transfer_tie")
					|| EQUALSTR(obj->querystr("base_name"), "huicheng_juanzhou"))
				{
					if(check_rent(me))
					{
						message_vision("$N͵͵�ó�$n�������������ס������ѽ�Ķ������£���", me, obj);
						return 1;
					}
				}
			}

			//�ػ�hit��kill��fight��cast��join��ָ��
			if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0
				|| strcmp(comm, "cast") == 0 || strcmp(comm, "join") == 0||strcmp(comm, "guard") == 0)			
			{
				CContainer * obj = Present(atol(tar));
				if(! obj) return 0;
				
//				if(! obj->is_character()) return 0;
				if( check_rent(me) || check_rent((CChar *)obj) )
				{
					message_vision("$N��ס$n���������У����ʲô��ȥ�㣡��", yongren, me);
					return 1;
				}
			}

			//�ػ�dropָ��
			if(strcmp(comm, "drop") == 0)
			{
				CContainer * obj = me->Present(atol(tar));
				if(! obj) return 0;
				
				if(obj->query_temp("yongren/rent"))
				{
					message_vision("$N͵͵�������ó�$n���붪�ڵ��ϡ�", me, obj);
					message_vision("$N��״�ȵ������ʲô������Ҫ�Ļ������ң�", yongren, me);
					return 1;
				}
			}

			//�ػ�giveָ��
			if(strcmp(comm, "give") == 0)
			{
				CContainer * obj = me->Present(atol(tar));
				if(! obj) return 0;

				//Ѱ��Ŀ��
				LONG target = 0;

				if(sscanf(arg, "to %ld", &target) != 1)
					return 0;

				CContainer * who = Present(target);
				if(who == yongren) return 0;	//���Ը�����

				if(obj->query_temp("yongren/rent"))
				{
					message_vision("$N͵͵�������ó�$n����ת�ָ��ˡ�", me, obj);
					message_vision("$N��״�ȵ������ʲô������Ҫ�Ļ������ң�", yongren, me);
					return 1;
				}
			}

			//�ػ�getָ��
			if(strcmp(comm, "get") == 0 )
			{
				//�ж���Ʒ�Ƿ�Ϸ�
				CContainer * obj = Present(atol(tar));
				if(! obj) return 0;

				if(obj->query_temp("yongren/rent"))
				{
					message_vision(snprintf(msg, 255, "$N����ȥ��%s�������$nһ�Ųȵ�����ָ�ϣ�", obj->name()), me, yongren);
					return 1;
				}

				if(obj->is_character() && check_rent((CChar *)obj))
				{
					message_vision("$N��Ȼ��ס$n��Ц�����������˰ɣ�", yongren, me);
					return 1;
				}
				if(userp(obj))
				{
					message_vision("$N�ɻ������$n�������ʲô��", yongren, me);
					return 1;
				}
			}			

			//�ػ�sellָ��
			if(strcmp(comm, "sell") == 0)
			{
				//�ж��Ƿ�����
				CContainer * obj = me->Present(atol(arg));
				if(! obj) return 0;

				if(obj->query_temp("yongren/rent"))
				{
					message_vision(snprintf(msg, 255, "$N������%s�������$n������ס����Ķ����컹��", obj->name()), me, yongren);
					return 1;
				}				
			}
		}
	}
	else
	{
		if(strcmp(comm, "housename") == 0)
			return housename(me, arg);
		else if(strcmp(comm, "housedesc") == 0)
			return housedesc(me, arg);
		else if(strcmp(comm, "addmaster") == 0)
			return addmaster(me, arg);
		else if(strcmp(comm, "findbaby") == 0)
			return findbaby(me);
		else if(strcmp(comm, "kickout") == 0)
			return do_kick(me, arg);
		else if(strcmp(comm, "paymoney") == 0)
			return do_paymoney(me, arg);
	}

	return CRoom::handle_action(comm, me, arg, tar);
}

CContainer * check_rent(CChar * me)
{
	if( EQUALSTR(querystr("owner"), me->id(1) )
		|| EQUALSTR(querystr("second_owner"), me->id(1)))
		return 0;

	//����
	DTItemList * list = me->Get_ItemList();
	POSITION p = list->GetHeadPosition();
	CContainer * obj;

	while(p)
	{
		obj = list->GetNext(p);
		if(obj->query_temp("yongren/rent"))
			return obj;		
	}
	
	return 0;
}

int valid_leave(CChar * me, const char * dir)
{
	//������Ʒ�������������
	if(EQUALSTR(dir, "����"))
	{
		CChar * who = (CChar *)PresentName("monster_yongren", IS_NPC);
		CContainer * obj = check_rent(me);
		if(who && obj)
			return notify_fail("%s������ס�㣬˵����%s���£���", who->name(), obj->name());
	}

	return CRoom::valid_leave(me, dir);
}

//���õڶ�����
int addmaster(CChar * me, char * arg)
{
	if(DIFFERSTR(querystr("owner"), me->id(1)))
	{
		say("�Բ���ֻ�л���������������ͬס��", me);
		SendMenu(me);
		return 1;
	}

	if(query("size") < 2)
	{
		say("�Բ���������䲻����ס�������ˡ�", me);
		SendMenu(me);
		return 1;
	}

	CUser * owner = find_online(arg);
	if(! owner)
	{
		say("�Բ��������������ʱ����ע�᷿����", me);		
		SendMenu(me);
		return 1;
	}
	
	set("second_owner", arg);
	update_register();

	tell_object(me, "OK.");
	return 1;
}

//�ϳ�ȥ
int do_kick(CChar * me, char * arg)
{
	char msg[255];
	CUser * who = find_online(arg);
	if(! who) return notify_fail("������˭��");

	if( EQUALSTR(querystr("owner"), who->id(1) ))
		return notify_fail("û����˼ҿ��Ƿ���������");

	if(who->environment() == this)
	{
		message_vision("$HIY$N����һ�ţ���$n�߳������⣡", me, who);

		//�Ȱ����ϵ�����Ʒ���£�
		DTItemList list;
		CContainer * obj;

		CopyList(&list, who->Get_ItemList());
		POSITION p = list.GetHeadPosition();

		while(p)
		{
			obj = list.GetNext(p);
			if(obj->query_temp("yongren/rent"))
			{
				obj->move(this);
				message_vision("$n��$N���ϵ���������", who, obj); 
			}
		}

		list.RemoveAll();

		who->move(load_room(querystr("belong")));
	}
	else
	{
		tell_object(me, snprintf(msg, 255, "��ܾ���%s������ã�", who->name(1)));
	}
	
	if(EQUALSTR(who->querystr_temp("invite"), querystr("owner") ))
		who->delete_temp("invite");

	return 1;
}

//���÷�������
int housename(CChar * me, char * arg)
{
	string msg;
	
	msg = check_legal_name(arg);
	if(msg.length())
	{
		say(msg.c_str(), me);
		SendMenu(me);
		return 1;
	}
	
	if(! LockData(1)) return 0;
	
	if(! Load())	//�˷����Ѿ�������
	{
		call_out(remove_me, 1);
		return 1;
	}

	set_name(arg);

	update_register();
	LockData(0);
	
	tell_object(me, "OK.");
	
	return 1;
}

//���÷�������
int housedesc(CChar * me, char * arg)
{
	int len = strlen(arg);
	if(len < 1 || len > 500)
	{
		say("�����ķ�������д�ü��Ư���㡣", me);
		SendMenu(me);
		return 1;
	}

	if(! valid_string(arg))
		return 0;
	
	if(! LockData(1)) return 0;
	
	if(! Load())	//�˷����Ѿ�������
	{
		call_out(remove_me, 1);
		return 1;
	}

	set("desc", arg);

	Save();	
	LockData(0);
	
	return 1;
}

//����ע����Ϣ
void update_register()
{
	char msg[255];
	CRoom * r = load_room(querystr("belong"));
	
	if(! r->Query(IS_RESIDENT))
	{
		g_Channel.do_channel(&g_Channel, 0, "sys", 
			snprintf(msg, 255, "update:����%s��ע�������%s���ǿ����õľ�ס����", name(1), r->name(1)));
		return;
	}
		
	((CRresident *)r)->update_register(this);

	Save();
}

virtual int do_look(CChar *me)
{
	say(Long(), me);
	say(querystr("desc"), me);
	
	if(EQUALSTR(querystr("owner"), me->id(1))
		|| EQUALSTR(querystr("second_owner"), me->id(1)))
	{
		AddMenuItem("�ܾ���������", "$2kickout 0 $2", me);
		AddMenuItem("�޸ķ�������", "$2housename 0 $2", me);
		AddMenuItem("�޸ķ�������", "$2housedesc 0 $2", me);

		if(EQUALSTR(querystr("owner"), me->id(1)) && query("size") > 1)
			AddMenuItem("����������ͬס", "$2addmaster 0 $2", me);

		if(EQUALSTR(me->querystr("gender"), "Ů��") && me->query("child"))
			AddMenuItem("�ұ���", "$0findbaby", me);
	}

	SendMenu(me);
	return 1;
}

int findbaby(CChar * me)
{
	if(DIFFERSTR(me->querystr("gender"), "Ů��"))
	{
		say("С����ȥ���ˣ���������Ӱ������ҡ�", me);
		SendMenu(me);
		return 1;
	}
		
	CChar * baby;
	char msg[255];

	for(int i=1; i<= me->query("child"); i++)
	{
		//�����ں��ӵĸ�����
		if(DIFFERSTR(me->querystr(snprintf(msg, 255, "child_%ld/father", i)), querystr("owner")))
			 continue;			

		baby = NULL;
		LONG baby_id = query_temp(snprintf(msg, 255, "baby_%ld", i));

		if(baby_id)
			baby = find_npc(baby_id);
		
		if(! baby)
		{
			baby = load_npc("monster_baby");

			set_temp(msg, baby->object_id());
					
			baby->set("gender", me->querystr(snprintf(msg, 255, "child_%ld/gender", i)));
			baby->set("long", me->querystr(snprintf(msg, 255, "child_%ld/long", i)));
			baby->set_name( me->querystr(snprintf(msg, 255, "child_%ld/name", i)));
			baby->set("father", me->querystr(snprintf(msg, 255, "child_%ld/father", i)));
			baby->set("mother", me->querystr("id"));
			baby->set("icon", CChar::boy1);
			if(EQUALSTR(baby->querystr("gender"), "Ů��") )
				baby->set("icon", CChar::girl1);
		
			baby->move(this);
			message_vision("$N�Ӵ������˳�����", baby);			
		}
		
		if(baby->environment())
			AddMenuItem(snprintf(msg, 255, "%sλ��%s�", baby->name(), (baby->environment())->name()), "", me);		
	}

	SendMenu(me);
	return 1;
}

//�����Ƿ�����
void check_pays()
{
	char msg[255];

	CRoom * r = load_room(querystr("belong"));

	if(! r->Query(IS_RESIDENT))
	{
		g_Channel.do_channel(&g_Channel, 0, "sys", 
			snprintf(msg, 255, "check_pays:����%s��ע�������%s���ǿ����õľ�ס����", name(1), r->name(1)));
		return;
	}
	
	int days = ((CRresident *)r)->count_days(querystr("owner"));
	LONG price = ((CRresident *)r)->house_price();

	if(query("size") < 2) price /= 2;
	set("need_pays", days * price / 500);
}

//�����ʵ�
//���ɷ����ʵ�
int do_paymoney(CChar * me, char * arg)
{
	char msg[255];
	LONG pay = query("need_pays");
	if(! pay) return 0;

	if(! strlen(arg))
	{
		say(snprintf(msg, 255, "һ��%s�Ĺ�����ý��㵥��\n\n��ֹ�����ۼƷ��úϼ�%ld��\n\nע�⣺����Ƿʱ�䳬��һ���£�����ʧȥ������ľ�סȨ��", 
			name(), pay),	me, "�����ʵ�");
		AddMenuItem("����", "$0paymoney 0 1", me);
		AddMenuItem("�������", "", me);
	}
	else
	{
		if(! LockData(1)) return 0;
		
		if(! Load())	//�˷����Ѿ�������
		{
			call_out(remove_me, 1);
			return 0;
		}
		
		check_pays();
		pay = query("need_pays");

		if(! CMoney::Player_Pay(me, pay))
		{
			say("�Բ����ֽ��㣡", me);
		}
		else
		{
			del("need_pays");
			set("pay_time", current_time);
			update_register();
		}

		LockData(0);
		say(snprintf(msg, 255, "֧����%ld������ʵ���", pay), me);		
	}

	SendMenu(me);
	return 1;
}


ROOM_END;





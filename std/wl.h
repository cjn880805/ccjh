#include "../server/Room.h"
#include "../server/Npc.h"

#define WL_BEGIN(room_name)	class room_name : public CRwl	{	public:	room_name(){};	virtual ~room_name(){};
#define WL_END		};	

ROOM_BEGIN(CRwl);

virtual void setup()
{
	CRoom::setup();

	CContainer * env = load_room("jy");
	if(query("yuandan") && env->query("�")&& !query("start"))
	{
		add_item("cai");
		add_item("cai");
		add_item("cai");
		add_item("cai");
		add_item("tang");
		add_item("guo");
		add_item("jiu1");
		set("start",1);
	}
}

virtual void init(CChar *me)
{
	if(userp(me))
	{
		DTItemList * list = me->Get_ItemList();
		POSITION p = list->GetHeadPosition();
		CContainer * obj;
		while(p)
		{
			obj = list->GetNext(p);
			if(userp(obj) )
			{
				tell_object(me, "���ﲢ����ӭ�Ƿ�Ǳ���ߡ�");
				obj->move(load_room("��ɽ������"));

			}
			else if(EQUALSTR(obj->querystr("id"), "fight_room"))
			{
				tell_object(me, "���ﲢ����ӭ�Ƿ�Ǳ���ߡ�");
				me->move(load_room("̩ɽ��ʶ�"));
			}
		}
	}
}

int handle_action(char *comm, CChar *me, char * arg, char * target)
{
	if(me->query("grant") < 50)
	{
		if(me->query_temp("jy/no_say"))
		{
			tell_object(me, "�������һЩ��Ϊ��������Ϸ�����������Ѿ����ٻ�ӭ���ˣ�");
			me->move(load_room("��ɽ������"));
			return 1;
		}
		else 
		{
			if(query("biwu"))
			{
				if( !strcmp(comm, "go")||!strcmp(comm, "talk") )
					return 0;
				tell_object(me, "$HIR�����صأ��Ͻ�����!\n����ȡս��������ѡ����Ӧ�����Ǽ�Ա������/talk��������ȡ��");
				return 1;
			}
			else
			{
				CContainer * obj = Present(atol(target));
				if(userp(obj))
				{
					if(!strcmp(comm, "kill")||!strcmp(comm, "look")||!strcmp(comm, "fight")||!strcmp(comm, "cast")
						||!strcmp(comm, "invite")||!strcmp(comm, "talk"))
					{
						tell_object(me, "�㲻���������������ЩΣ�ն�����");
						return 1;
					}
				}
				if(!strcmp(comm, "guard"))
				{
					tell_object(me, "�����Լ��ģ������˵���ʲô��");
					return 1;
				}
				if(!strcmp(comm, "ad")||!strcmp(comm, "makelove")||!strcmp(comm, "rumor")||!strcmp(comm, "chat")
					||!strcmp(comm, "party")||!strcmp(comm, "corps")||!strcmp(comm, "wakeup"))
				{
					tell_object(me, "����������������ʲô���ã�Ҫ��Ҫ�ֳ�ȥ���š�");
					return 1;
				}
				if(!strcmp(comm, "cast"))
				{
					tell_object(me, "�㲻���������������ЩΣ�ն�����");
					return 1;
				}
			}
		}
		return 0;
	}

	if(strcmp(comm, "chblk") == 0)
	{
		CContainer * obj = Present(atol(target));
		if(! obj) return notify_fail("��ѡ�е�ǰ����Ŀ��.");
		obj->set_temp("jy/no_say", 1);
		message_vision("$N����һ�齺����ž��һ������$n���ϡ�", me, obj); 
		return 1;
	}
	
	return CRoom::handle_action(comm, me, arg, target);
}

virtual void reset()
{
	CRoom::reset();

	CContainer * env = load_room("jy");
	if(query("yuandan") && env->query("�")&& !query("start"))
	{
		add_item("cai");
		add_item("cai");
		add_item("cai");
		add_item("cai");
		add_item("tang");
		add_item("guo");
		add_item("jiu1");
		set("start",1);
	}
}

ROOM_END;




//ziqitai.h

//Sample for room: ����̨
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_ziqitai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����̨");
	
	add_npc("pub_compere");
	add_door("��ɽ������С·2", "��ɽ������С·2", "��ɽ����̨");

	set("long", "����̨�����������ڣ����ɲ������գ���Ϊ������ǣ�û�������죬ɽ��֮�о��������������֡�");  
	set("biwu",1);
	set("sleep_room",1);
    
 };

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
			CContainer * obj = Present(atol(target));
			if(!strcmp(comm, "look")||!strcmp(comm, "fight")||!strcmp(comm, "cast"))
			{
				tell_object(me, "δ�����룬�����˵Ȳ����ڴ�������");
				return 1;
			}
			else if(!strcmp(comm, "kill"))
			{
				if(!me->query_temp("����") )
				{
					tell_object(me, "δ�����룬�����˵Ȳ����ڴ�������");
					return 1;
				}
				else if(!userp(obj))
				{
					return 1;
				}
				else if(!(CChar *)obj->query_temp("����"))
				{
					tell_object(me, "��Ķ�����δ�����д��ʸ��뻻һ�����ֻ���������ʸ�����д衣");
					return 1;
				}
				else
				{
					me->set_temp("biwu/go",1);
					obj->set_temp("biwu/go",1);
					me->delete_temp("����");
					obj->delete_temp("����");
					return 0;
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
ROOM_END;

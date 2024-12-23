//shishi2.h

//Sample for room: ʯ��2
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRSheShenYa_shishi2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ��2");


	add_door("������ʯ��", "������ʯ��", "������ʯ��2");
	//add_door("��ң�ֹ�����", "��ң�ֹ�����", "������ʯ��2");

	set("long","����һ�����µ�����ʯ�ң�������Ըо��õ���ֻ��ǿ�ҵ�ɱ�����Լ�����ص׵�һЩ���ŵ���ζ����΢���ĵƹ��£��㾹Ȼ�����и���վ������������º�����·��");

/*****************************************************
	set("exits", ([
		"up" : __DIR__"fangjian2",
		"down" : __DIR__"shishi5",
	]));
	set("objects",([
		__DIR__"npc/qingyun" : 1,
	]));
*****************************************************/
};

void init(CChar *me)
{
	if(userp(me))
	{
		remove_call_out(do_out);
		call_out(do_out, 10, me->object_id());
	}
}

static void do_out(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob->Present(param1);
	if(! me) return;

	tell_object(me, "һ�ɺ����������������ϸ�۲�һ�£��ƺ�ǰ���Ĵ�ʯ�����ƶ���");
}

//�ƿ��Ž�����ң��
int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(strcmp(comm, "push") == 0)
	{
		message_vision("ǽ��ͻȻ��ת������$Nת�۵���ɽ���⡣", me);
		me->move(load_room("��ң�ֹ�����"));
		return 1;
	}

	return 0;
}

ROOM_END;

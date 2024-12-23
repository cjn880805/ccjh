//hanhanquan.h

//Sample for room: ����Ȫ
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_hanhanquan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ȫ");
	
	add_npc("pub_gongzi");      //add by zdn 2001-07-16


	add_door("������ɽׯ", "������ɽׯ", "���ݺ���Ȫ");

	set("long", "��ɽ��������һ����Ȫ��ϵ�ϳ�������ɮ�������������䣬���һǧ�İٶ��ꡣ��˵Ȫ��ͨ��������������ӿȪ����ˮ������Ϊ�����µ���Ȫ����ʯ�̡�����Ȫ�����֣�ϵ�������������⡣" );
	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;

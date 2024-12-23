//yuquan.h

//Sample for room: ������Ȫ
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_yuquan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������Ȫ");

	//add npcs into the room
	add_npc("pub_youke2");
	add_npc("pub_jiaojindaoren");

	add_door("������ʯ���5", "������ʯ���5", "������Ȫ");

	set("long","��Ȫ�½�����Ȫɽ�ϣ�ԭ�������¡��߽���Ȫ�£�ֻ�������м���ˮ��(pond)���������ǳ�����ɽ��·��");
    

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

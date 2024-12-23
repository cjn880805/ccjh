//kedian.h

//Sample for room: �͵�
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_kedian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�͵�");

	//add npcs into the room
	add_npc("pub_xiaoer2");
	
	add_door("�����ϲ�ݳ�", "�����ϲ�ݳ�", "����ǿ͵�");

	set("long", "����ϲ�ݳ���Ψһ��һ�ҿ�ջ��ר�ŽӴ��������̣�����ǳ���¡����С����������æ������ת���˼���ƫԶ��ȴ�����ƿ��׿��ˣ�ס��һ��ֻҪ�������ӡ�" );
	set("no_fight", 1);
	set("valid_startroom", 1);
    set("sleep_room",1);
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

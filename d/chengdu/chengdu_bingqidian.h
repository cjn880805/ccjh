//bingqidian.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_bingqidian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add npcs into the room
	add_npc("pub_tanglong");
	
	add_door("�ɶ���", "�ɶ���", "�ɶ�������");

	set("long",	"������һ��СС����ı����̣��������ı����ɲ�Ѱ���������Ȼ�����ѵ�һ�������õ��˸���ϡ�١��ƹ�����������ֱ��ë����ת���Ϳ���ǽ�ϵ�����(zhaopai)��"	);

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

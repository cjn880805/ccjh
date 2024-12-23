//dating.h

//Sample for room: ����ɽ����
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_dating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ����");

	//add npcs into the room
	add_npc("pub_yahuan");
	add_npc("btshan_ouyangfeng");
	
	add_door("����ɽԺ��", "����ɽԺ��", "����ɽ����");
	add_door("����ɽ������", "����ɽ������", "����ɽ����");

	set("long", "���ǡ�����ɽׯ���Ĵ������ڲ����輫������������һ�ź�ɫ̴ľ����������·��ž����Ļ�ƿ��һЩ���Ĵ������ıڹ������ҵ��ֻ���.������������������գ����Բ��������˴����");
	set("valid_startroom",1);

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

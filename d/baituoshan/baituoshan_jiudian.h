//jiudian.h

//Sample for room: �Ƶ�
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_jiudian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�Ƶ�");

	//add npcs into the room
	add_npc("pub_xiaoer2");
	
	add_door("����ɽ����", "����ɽ����", "����ɽ�Ƶ�");

	set("long", " ������һ�Ҷ�����ɫ�ľƵ꣬���ڵش�������ɽ���£��Ƶ���Թ�Ӧ��ζʳƷ�������⡣�����ԭ���Ͷ����������ʣ����ԾƵ�������¡���Ƶ껹��Ӫ��ɢװ�Ƶ�ҵ��");
    set("resource/water", 1);

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

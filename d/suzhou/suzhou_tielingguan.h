//tielingguan.h

//Sample for room: �����
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_tielingguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����");

	//add npcs into the room
	add_npc("pub_wujiang");/////////////////////////
	add_npc("pub_bing");
				

	add_door("���ݷ���", "���ݷ���", "���������");

	set("long", "�سʳ����Σ�שʯ�ṹ�����е������¥Ϊ�½�������صش�ˮ½Ҫ��ǵ�¥���ȿ����������ܷ�����������ԫ���˺ӡ�ʯ������ɵ����Ϲ��£���ʱ��Ϊ�˷����ϵֿ����ŵ����ܡ�" );

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

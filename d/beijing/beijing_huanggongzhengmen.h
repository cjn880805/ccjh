//huanggongzhengmen.h

//Sample for room: �ʹ�����
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRBeiJing_huanggongzhengmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ʹ�����");

	//add npcs into the room
	add_npc("pub_shiwei2");
	add_npc("pub_wujiang");
	add_npc("pub_bing");
	
	add_door("����", "����", "�����ʹ�����");

	set("long", " ����ǻʹ����š�Ρ����ΰ�ĳ�ǽ�ϣ�'�Ͻ���'��������ʮ�����ۣ����ƻԻ͡�һ�����ߵĸ�ʾ(gaoshi)����ǽ�ϣ����ٱ��������ԡ�" );
	set("outdoors", "city2");

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

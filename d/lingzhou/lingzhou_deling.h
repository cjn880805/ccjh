//deling.h

//Sample for room: ���ݵ���
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_deling);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݵ���");

	//add npcs into the room
	//add_npc("pub_shiwushi");/////////////////////////

//	add_door("���ݳ���", "���ݳ���", "���ݵ���");
//	add_door("���ݹ���", "���ݹ���", "���ݵ���");

	set("long", "�������Ԫ껵ĸ����Ե�������Ĺ����ʮ�׸����ף�Ϊ������������ߴ�Ҳ���������Ľ�������ǰ���Ҹ�������ʯ����ʿ��������ǰ�к���������Χ�ɵ�ƽ̨������ʯ��ʯ��һӦ��ȫ��");  

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

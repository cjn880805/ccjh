//jsjdg3.h

//Sample for room:  ���Ҿ�ʮ�ŵ���3
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_jsjdg3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���Ҿ�ʮ�ŵ���3");
	
	add_npc("pub_whitelady");             // add by zdn 2001-07-14

	add_door("���Ҿ�ʮ�ŵ���4", "���Ҿ�ʮ�ŵ���4", "���Ҿ�ʮ�ŵ���3");
	add_door("���Ҿ�ʮ�ŵ���2", "���Ҿ�ʮ�ŵ���2", "���Ҿ�ʮ�ŵ���3");

	set("long","���������ġ���ʮ�ŵ��ա�����·����������ǧ�۰ٻء���˵��ȥ���и�������ķ�ɮ���ˣ���һ������·�������������������ǵ�֪�˴��о�����û�󣬱���Ҳ���˸�������Ĳ�ľ�����ԡ����ӡ���֮���ɴ˶�����ǧ���֣�������϶���");

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
//hudiequan.h

//Sample for room: ����Ǻ���Ȫ
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_hudiequan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǻ���Ȫ");

	add_npc("pub_cunfu");
	add_npc("pub_flowerg");  //add by zdn 2001-07-12 
	add_npc("xy_shiganlu");//����ذ��ѡ�ʯ��¶  ��ң������NPC

	add_door("����������ǰ", "����������ǰ", "����Ǻ���Ȫ");
	add_door("������ּ�С��1", "������ּ�С��1", "����Ǻ���Ȫ");

	set("long", "����Ȫ���Եø�������ʪ�󣬴����ĺ�����������˷����㼯�������£������У��������裬��ǧ����ֻ�ʵ�������һ����ʹ�����û��Ž��ء��ر����ں���Ȫ�ϣ�˳���ǵ���������������������һֻҧ��һֻ��β�����γ�ǧ�ٸ�����������������Ͷʯ��ɢ���������˾�̾����ۡ�" );
	
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





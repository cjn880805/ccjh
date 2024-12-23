//huagang.h

//Sample for room: ���ݻ��۹���
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_huagang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݻ��۹���");
	
	add_npc("pub_flowerg");            // add by zdn 2001-07-14
	add_npc("helpnpc013");
	CContainer * env = load_room("pk");
	if(env->query("�")==1)
		add_npc("wiz_203");


	add_door("�����յ�6", "�����յ�6", "���ݻ��۹���");

	set("long"," ֻ��������һС����һ�����ź����档��������Ⱥ����������Ͷ�������º��㣬��ʳ������л������԰ʱ����ʫһ�ס����Ⱥ�������࣬����ž��ҷ��㡣��թ������������������˿��˺���");

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

//liuyuan.h

//Sample for room: ��԰
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_liuyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��԰");

	//add npcs into the room
	add_npc("pub_lady1");/////////////////////////
	CContainer * env = load_room("pk");
	if(env->query("�")==1)
		add_npc("wiz_101");

	add_door("������", "������", "������԰");
	add_door("���ݺɻ���", "���ݺɻ���", "������԰");	

	set("long", "��԰�����ݵ�һ������֮һ�����Խṹ���ֽ��ܡ����û�����֡�װ�ξ������Ŷ����С����е�һ��԰��֮����  " );

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

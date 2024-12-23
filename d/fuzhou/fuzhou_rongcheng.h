//rongcheng.h

//Sample for room: �ų���
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_rongcheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ų���");

	//add npcs into the room
	add_npc("pub_xiaoer2");
	
	add_door("���ݶ�", "���ݶ�", "�����ų���");
	add_door("�����ų����¥", "�����ų����¥", "�����ų���");

    set("long", "�ų�����ȫʡ���Ŀ͵꣬����ǳ���¡������οͶ�ѡ��������ţ�������������������ʡ�ķ������顣��С����������æ������ת�����ݵķ�������ʵ������˳����������¥˯��ȥ��ǽ�Ϲ���һ������(paizi)��" );
	set("valid_startroom", 1);
    set("sleep_room",1);	
	set("no_fight", 1);

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

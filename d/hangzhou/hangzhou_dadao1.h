//dadao1.h

//Sample for room: �����غ����1
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_dadao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����غ����1");
	
	add_npc("pub_oldwoman");          // add by zdn 2001-07-14

	add_door("���ݹ�ׯ", "���ݹ�ׯ", "�����غ����1");
	add_door("�����غ����2", "�����غ����2", "�����غ����1");
	add_door("������ʯ���5", "������ʯ���5", "�����غ����1");

	set("long","һ�����Ĵ����ȴ����ϡ�١�ԭ��������·ס�ŵĶ��Ǵ�ٹ��ˡ������羰����֮����ȴ�Ե�һƬ��ɪ��·��������һ��ׯ԰��������ϱ����졣");

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

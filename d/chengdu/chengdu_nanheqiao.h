//nanheqiao.h

//Sample for room: �Ϻ���
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_nanheqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�Ϻ���");

	add_npc("pub_huanu");
	add_npc("pub_jianke");   //zdn 2001-07-12 add

	add_door("�ɶ���", "�ɶ���", "�ɶ��Ϻ���");
	add_door("�ɶ�Ϫ��С·", "�ɶ�Ϫ��С·", "�ɶ��Ϻ���");
	add_door("Ѫ����ѩɽ·1", "Ѫ����ѩɽ·1", "�ɶ��Ϻ���");

	set("long",	"�����ǳɶ��������Ϻ��š����Ӻ��ϺӼг��������ǻ�������츮֮�����׸�֮�ء���ˮ���±�͸�������������ţ���������佻�Ϫ�ˡ�"	);

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

//xiaolu1.h

//Sample for room: ��������С·1
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_xiaolu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������С·1");


	add_npc("pub_liujue");

	add_door("�������д�·1", "�������д�·1", "��������С·1");
	add_door("��������С·2", "��������С·2", "��������С·1");

	set("long", "���Ƕ����ϵ�һ���Ӳݴ�������С·��������ƽʱûʲô�˼���·�߿��Ų�֪����Ұ�������ߵ�������Ȼ�ߴ�ͦ�Ρ�����͸�����յ��������ǰ߲߰�����Ӱ�ӡ�");  
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




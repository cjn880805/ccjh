//jinzhihe.h

//Sample for room: ����ǽ�֭����
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_jinzhihe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ǽ�֭����");

	add_npc("pub_bing");   // add by zdn 2001-07-12 

	add_door("����Ǿ���1", "����Ǿ���1", "����ǽ�֭����");
	add_door("�����ɽ��С��", "�����ɽ��С��", "����ǽ�֭����");
	add_door("������سص̰�1", "������سص̰�1", "����ǽ�֭����");

	set("long", "����λ����֭���ϣ�ԭ������һ���ز��£������Ժ��ϡ�Ψ��һ��ʯ�̾���(jingzhuang)�������С��˴�Ϊ��׶״���߲�ʯ�񡣸�Լ����ߣ�����Ϊ�˽��ε���ʯ�����Ͽ��������������֮���н�ʯ�����Ǳ���֮���ܣ������ϲ�֮��ʯ��" );
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

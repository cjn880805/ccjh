//xuanmiao.h

//Sample for room: �����
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_xuanmiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����");
	
	add_npc("pub_baibian");       //add by zdn 2001-07-16


	add_door("������", "������", "���������");

	set("long", "��һ�߽�����ۣ���������������ƣ�����ڶࡣ��������Ъɽʽ���ݼ���ʮ���ף����иߴ������ʮ���������¶�ƽ�������ܽ���������ʺ�󣬵���������ש�������������Ϲ����ŵ������ʮ���׵�������������񣬷���ׯ�ϣ�������ȣ���ʧΪ���̵����еľ�Ʒ�� " );
 	set("outdoors", "suzhou");
	
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

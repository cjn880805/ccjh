//bgs.h

//Sample for room:  ���ұ�����
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_bgs);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ұ�����");

	add_npc("pub_guest");
	
				
	add_door("���ұ�����ɽ��", "���ұ�����ɽ��", "���ұ�����");
	add_door("��������1", "��������1", "���ұ�����");

	set("long","�������Ƕ�üɽ�����Ժ֮һ��������ɽ���죬���յ���۵�߷�������ߣ���ģ��󡣵��ڷ������������������������ڷ����Ծ�������������������һ��������(ta)������������Լ����ɴ�����¡�");
    
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

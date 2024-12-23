//qsjie2.h

//Sample for room:  ������ʯ��
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_qsjie2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ��");

	add_npc("pub_jianke");     // add by zdn 2001-07-14
				
	add_door("���ұ�����ɽ��", "���ұ�����ɽ��", "������ʯ��");	
	add_door("����С·", "����С·", "������ʯ��");
	add_door("����ǹٵ�1", "����ǹٵ�1", "������ʯ��");
	add_door("��ٹȽ���С·1", "��ٹȽ���С·1", "������ʯ��");		

	set("long","�Ѿ��Ƕ���ɽ�����ˡ�����һ��ͨ�����ҵ���ʯ�ף�����������Σ�����ʮ�����¡����Ϸ�ͨ����گ�Ĵ���������ߺ������˴��˸�С���");

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

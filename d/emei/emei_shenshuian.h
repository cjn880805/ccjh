//shenshuian.h

//Sample for room:  ������ˮ��
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_shenshuian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ˮ��");
	
	add_npc("emei_yanziyi");        //add by zdn 2001-07-20


	CBox * box = Add_Box();
	box->add_object("coin", 60000);	//put 100 coind into box

	box->set_name( "����֮ӡ");		//set box's name
	box->set("id","enchantment");
	box->Locked("���", 18000);

				
	add_door("���Ҵ�����", "���Ҵ�����", "������ˮ��");
	add_door("���Ҹ�����", "���Ҹ�����", "������ˮ��");
	add_door("�����з���", "�����з���", "������ˮ��");

	set("long","��ˮ��λ�ڱ��Ʒ��£���ǰ�д��ʯ����ҺȪ��Ȫ��ʯ�£��峺�ޱȣ����겻�ԡ�һ����������������ٲ��䣬������Χ���ߴ�ʮ���ɡ��Ա��и����֣��ɴ������з��£����´����");

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

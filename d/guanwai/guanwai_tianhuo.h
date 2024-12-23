//tianhuo.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_tianhuo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	add_npc("guiyun_wanyankang"); 
	add_npc("guiyun_wanyanhonglie"); 
	add_npc("guiyun_jinbing");
	add_npc("guiyun_jinbing");       // add by zdn 2001-07-20

	set("monster_chance", 50);

	add_door("�������ŷ�", "�������ŷ�", "��������");
	add_door("���⻪�Ƿ�", "���⻪�Ƿ�", "��������");

	set("long","��鶺Ӷ����������ŷ���š��嶥��ӥ���ľ���ɽ����ʯ������������أ�������ӥ��塣�����أ�������˫�⣬�б�һ�ߣ��л�Ȼ���ʡ����˲���˼��֮Ȥ�����ഫΪ������ˮ������ʯ���ɫ����������ᣬ��Ȥ������" );
    

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

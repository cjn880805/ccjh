//qiandian.h

//Sample for room: ǰ��
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_qiandian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ǰ��");

	//add npcs into the room
	add_npc("pub_taijian");
	
	add_door("�������", "�������", "����ǻʹ�ǰ��");
	add_door("����ǻʹ�����", "����ǻʹ�����", "����ǻʹ�ǰ��");
	add_door("����ǻʹ�ƫ��", "����ǻʹ�ƫ��", "����ǻʹ�ǰ��");
	add_door("����ǻʹ����ŷ�", "����ǻʹ����ŷ�", "����ǻʹ�ǰ��");

	set("long", "�����Ǵ�����ʹ���ǰ���ש���߽���ʮ�־��ɣ�����������������������巺������ڴ˵��˴�����ƫ�����ϵ�С�������նԵ��������İ��������Էθ���ʮ����ϡ������͵�������԰, �����ǻʹ����š�" );

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

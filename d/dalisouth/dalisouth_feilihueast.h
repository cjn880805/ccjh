//feilihueast.h

//Sample for room: ��������
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_feilihueast);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	set("resident", "ϲ��");

	add_npc("pub_youke");
	add_npc("pub_flowerg");    //add by zdn 2001-07-13

	add_door("��������ڳ�", "��������ڳ�", "�������������");
	add_door("����Ǻ�����", "����Ǻ�����", "�������������");
	add_door("�������������", "�������������", "�������������");

	set("long", "��վ���������Ķ��������µ���·�ƺ��������ϱ��Ĵ�����������ֻ�����۵�㣬���ǲ����̨���񷤡�·�߾����������֣�̨�ĵ���¥�����֡�������ȥ�Ĳ�·ͨ�����������Բ�����·����ֱ�����ڳǡ�" );
};


RESIDENT_END;

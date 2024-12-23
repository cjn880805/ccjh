//yangzong.h

//Sample for room: �����������
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_yangzong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����������");

	set("resident", "������");

	//add npcs into the room
	add_npc("pub_bshangfan");
	add_npc("dali_jianghuyiren");     //add by zdn 2001-07-20
	
	add_door("�����ɽ·8", "�����ɽ·8", "�����������");
	add_door("�����ũ��4", "�����ũ��4", "�����������");
	add_door("�����ɣ��", "�����ɣ��", "�����������");
	add_door("���������", "���������", "�����������");

	set("long", "������ǿ�ڲ��Ĵ�����ôЩ����ľ۾�����ôЩ�����ǰ��ĵ�һ֧���˴�Ҳ��ɽ���С��ƽԭ����������һƬ��ˮ��������������ط���΢ƫԶЩ�������൱���ٵİ����������ڸ��������Ϸ��е�·ͨ����������" );
	
};

RESIDENT_END;

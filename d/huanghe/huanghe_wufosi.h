//wufosi.h

//Sample for room: �ƺ������
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_wufosi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ������");
	
	add_npc("pub_dibao");          //add by zdn 2001-07-14

	add_door("�ƺ�ʯ��", "�ƺ�ʯ��", "�ƺ������");

	set("long","������һ����������������Χȫ��ɳ������������Ѿ������������п������ɳ����ң��Ӱ���Ľ���������ϡ���Ա���������¡������֣�Ψһ���������Ľ����Ǵ����ݶ���ȫ�ǿ�����ǿ���������紵�����������ġ���---��---������");
	

/*****************************************************
	set("exits", ([
		"south"     : __DIR__"shimen",
	]));
********************************************/
};


CHANGAN_END;

//weifen.h

//Sample for room: �ƺ�μ������
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_weifen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�μ������");
	
	add_npc("pub_menmian");   //add by zdn 2001-07-14

	add_door("�ƺ�1", "�ƺ�1", "�ƺ�μ������");
	add_door("�ƺӰ���1", "�ƺӰ���1", "�ƺ�μ������");

	set("long","�ںӺ�μ�ӻ���ƺӣ���������ˮ�ƣ�Ҳ�����˸������ɳ������Ӷ��ǽ����������¡�");
    

/*****************************************************
	set("exits", ([
		"south" : __DIR__"huanghe1",
		"north" : __DIR__"huanghe_1",
		"southwest" : "/d/heimuya/road5",
		"northeast" : "/d/heimuya/dukou2",
	]));
********************************************/
};


CHANGAN_END;

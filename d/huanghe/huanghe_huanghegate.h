//huanghegate.h

//Sample for room: �ƺӰ�կ��
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghegate);

virtual void create()			//Call it when Room Create
{
		//set name of our room
	set_name( "�ƺӰ�կ��");
	
	add_npc("huanghe_sha");        //add by zdn 2001-07-14


	add_door("�ƺӰ���1", "�ƺӰ���1", "�ƺӰ�կ��");
	add_door("�ƺӹ㳡", "�ƺӹ㳡", "�ƺӰ�կ��");

	set("long","����һ������׳�۵�կ�ţ����и߹���һ���д�š��ƺӰ�������֡�կ�����ĸ߹ң���ģ��С���ƺӰ��ǻƺ��ذ���һ�����ᣬƽ�շ�����裬��ѹ���գ������ˡ�����ɳͨ���书��տ�������������������̺��������˵ȸ��ֽύ��������ƺƴ󡣾���������˹��ᣬ������������");

/*****************************************************
	set("exits", ([
		"east"  : __DIR__"huanghe1",
		"west"  : __DIR__"guangchang",
	]));
	set("objects", ([
		__DIR__"npc/ma" : 1,
		__DIR__"npc/shen" : 1,
	]));
********************************************/
};


CHANGAN_END;
			
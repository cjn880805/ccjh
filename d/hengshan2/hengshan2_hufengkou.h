//hufengkou.h

//Sample for room: ��ɽ�����
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_hufengkou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�����");


	add_door("��ɽ������", "��ɽ������", "��ɽ�����");
	add_door("��ɽ������", "��ɽ������", "��ɽ�����");

    set("long","�� '������' �� '����ͤ' ���͵���һ�����·ת�Ķ���·�ڣ�������һ����ڣ�������������绢Х���ȱ�ǿ����࣬����������:  '������·��ͷ�ǣ���ʯ�ഫ���Ϲ������������������������ż�ʹ��Ħ��"   );
    

/*****************************************************
        set("exits", ([ 
           "southwest" : __DIR__"daziling",
           "west"      : __DIR__"xuangengsong",
           "northeast" : __DIR__"guolaoling",
        ]));
********************************************/
};


ROOM_END;

//guolaoling.h

//Sample for room: ��ɽ������
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_guolaoling);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������");
	
	add_npc("pub_yuanziyi"); 

	add_door("��ɽ�����", "��ɽ�����", "��ɽ������");
	add_door("��ɽ������", "��ɽ������", "��ɽ������");
	add_door("��ɽͨԪ��", "��ɽͨԪ��", "��ɽ������");

    set("long","�⻬�������϶����ֲ������������ΰ��ӣ��Ӿ����Ĵ磬�������˵����ǵ�������е��Ź����ں�ɽ�޵�ʱ����Сë¿�ɴ˵��졣����·���»��������ò�ǣ¿���У�������Щ��ӡ������ʫ��:  '������·��ͷ�ǣ���ʯ�ഫ���Ϲ������������������������ż�ʹ��Ħ��' "   );
    

/*****************************************************
        set("exits", ([ 
           "northup"   : __DIR__"beiyuemiao",
           "westdown"  : __DIR__"tongyuangu",
           "southwest" : __DIR__"hufengkou",
        ]));
********************************************/
};


ROOM_END;

//liangong.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGueiYun_liangong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");
	
	add_npc("guiyun_duantiande");
	add_npc("guiyun_xiaolu");
	add_npc("guiyun_qiuqianzhang");        //add by zdn 2001-07-20


	add_door("����ׯ", "����ׯ", "����ׯ������");

    set("long"," �����ǹ���ׯ½��ׯ����������������½��ׯ����������֧��ϼ�ɳ������Է��в��þ���Ϊϰ������Ӳ��֮�ã������Ų���ľ׮�ͲݰС����߽��ϻ���������ɳ�ӣ��컨���ϵ���һ֧��ɳ����" );

/*****************************************************
	set("exits", ([
		"west"  : __DIR__"huayuan",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 3,
	]));
********************************************/
};


ROOM_END;

//liufudayuan.h

//Sample for room: ������Ժ
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRHengYang_liufudayuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������Ժ");

	//add npcs into the room
	add_npc("hengshan1_liuhong");
	add_npc("hengshan1_wuweiyi");
	add_npc("hengshan1_xiangguonian");
        add_npc("hengshan1_luduku");
        add_npc("hengshan1_liucao");
        add_npc("pub_liufuren");
	add_door("������", "������", "����������Ժ");

/*****************************************************
	set("long", " ������Ժ�����ڼ��źܶ཭�����ͣ�ԭ�����������������ϴ�ֵ�
�����ӡ�����ү���ں�����Ե�ܺã�����������Ȼ���٣���Ժ���Ѱ���
�ܶ������ӣ������������������֡�
" );
         set("exits", ([
            "north"  : __DIR__"liufudating",
            "out"    : __DIR__"liufugate",
        ]));
        set("objects", ([
                "/d/taishan/npc/dao-ke" : 1,
                "/d/taishan/npc/jian-ke" : 1,
                "/d/huashan/npc/haoke" : 1,
        ]));

********************************************/
};


ROOM_END;

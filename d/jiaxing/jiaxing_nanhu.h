//nanhu.h

//Sample for room: �����Ϻ�
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRJiaXing_nanhu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����Ϻ�");
	add_npc("gumu_liqingzhao");

	set("resident", "����");

	add_door("���˳�", "���˳�", "�����Ϻ�");
	add_door("����ׯ", "����ׯ", "�����Ϻ�");

	

/*****************************************************
	set("long", @LONG
�������̲������Ϻ������ϼ�ֻ�������ε������ϵ��οͺ�
��¥Ů������Ц����ˮ���û�д��Ƕɲ���ȥ�ġ�����֪��˭��
���׶���һЩľ׮��׮��Ǳ��ˮ��֮��һ����ĵط�����ʹ�ǲ���
�Ṧ��������ȥҲ����ˮ��Ư�����ӡ��ƺ�ˮ������Щʲô. ����
����Ǳ(out)�º�ȥ��Ѱʲô, ��Ҳ��֪��������. ֻ�����˴�
���ں����ҵ���ʲô����.
LONG );
	set("exits", ([
		"south"     : __DIR__"yanyu",
                "northwest" : __DIR__ "nanhu",
	]));
	set("outdoors", "quanzhou");
 ********************************************/
};


RESIDENT_END;

//xiaoyao_xiaolu1.h С·1
//�ز� 2002��12��5

XiaoYao_BEGIN(CRXiaoYao_xiaolu1);

virtual void create()
{
	set_name( "С·1");
	set("monster_chance",60);
	set("no_autosave",1);

	add_door("��ң��׷�¹۴���", "��ң��׷�¹۴���", "��ң��С·1");
	add_door("��ң��������ɽ��", "��ң��������ɽ��", "��ң��С·1");
	add_door("��ң��С·2", "��ң��С·2", "��ң��С·1");	

};

XiaoYao_END;

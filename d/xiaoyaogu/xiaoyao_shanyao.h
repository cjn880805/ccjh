//xiaoyao_shanyao.h ɽ��
//�ز� 2002��12��5

XiaoYao_BEGIN(CRXiaoYao_shanyao);

virtual void create()
{
	set_name( "ɽ��");

	set("monster_chance",60);
	set("no_autosave",1);

	add_door("��ң��������ɽ·1", "��ң��������ɽ·1", "��ң��������ɽ��");
	add_door("��ң��������ɽ·2", "��ң��������ɽ·2", "��ң��������ɽ��");

};

XiaoYao_END;

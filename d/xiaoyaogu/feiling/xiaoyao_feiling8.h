//xiaoyao_feiling8.h ����֮��
//�ز� 2003��3��15

XiaoYao_BEGIN(CRXiaoYao_feiling8);

virtual void create()
{
	set_name( "����֮��");
	set("no_autosave",1);
	set("index",8);

	add_item("shicheng");
	add_door("����֮������", "��ң�ȷ���֮������", "��ң�ȷ���֮��");
	add_door("����֮��", "��ң�ȷ���֮��", "��ң�ȷ���֮��");
	add_door("����֮������", "��ң�ȷ���֮������", "��ң�ȷ���֮��");

};

XiaoYao_END;

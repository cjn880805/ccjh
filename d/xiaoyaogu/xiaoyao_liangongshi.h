//xiaoyao_liangongshi.h ������
//�ز� 2002��12��5

XiaoYao_BEGIN(CRXiaoYao_liangongshi);

virtual void create()
{
	set_name( "������");

	set("no_get",1);
	set("no_fight",1);
	set("no_cast",1);

	add_npc("xy_xiaoyaonv");

	add_door("��ң��������", "��ң��������", "��ң��������");
	
};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		CContainer * env=me->environment();
		CContainer * xiaoyaonv=env->present("xiao yao nv");
		if(xiaoyaonv)
		{
			if(me->query("xy/renwu4") )
			{
				tell_object(me,"\n$HIY��ңŮ���ڱ�Ŀ��������ϰ�ڹ�������ͷ������������һ�Ƶ��������ɿ����������С����Ϊȴ�Ѳ�����\n");
			}
			else if(me->query("xy/renwu3"))
			{
				destruct(xiaoyaonv);
			}
		}
		
	}
}
XiaoYao_END;

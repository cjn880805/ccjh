//xiaoyao_jinyuehu.h ���º�
//�ز� 2002��12��5

XiaoYao_BEGIN(CRXiaoYao_jinyuehu);

virtual void create()
{
	set_name( "���º�");

	add_door("��ң��СϪ��", "��ң��СϪ��", "��ң�Ⱦ��º�");
	add_door("��ң���ٲ�", "��ң���ٲ�", "��ң�Ⱦ��º�");
	
};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query("xy/renwu7_2") && me->query("xy/renwu7_3")==2 &&!me->query("xy/renwu7_33")	&& !me->query("xy/renwu8"))
		{
			tell_object(me,"\n$HIC��ң��һ��һ���ʰ��ʯ�ӣ��ӽ����º��У�һ������������ӡ�");
			tell_object(me,"$HIC��Զ����һȺ���࿡��������ӵ������ۣ�������������˹�����\n");
			tell_object(me,"\n$HICŷ������һ���У�һ��Ŀ��ת���ض�������ۣ��ֺõ�˵����\n");
			tell_object(me,"$HIC����λ����Ī���Ǵ����µ���������Ů���������ò�����ɵ���Ů��С��������������ѽ����");
			tell_object(me,"$HIC����۳ԳԵ�Ц��������λ���ӿ����˵����������ˣ�������ǻ�ϲ�ý��أ���\n");
			tell_object(me,"\n$HICŷ��������������۵�����������һ������������ǡ�");
			tell_object(me,"$HIC�����������Ц��������");
			tell_object(me,"$HICһ�ԵĻ������Ӳ���ʾ����������ó�һ���������ʻ��͸�����ۣ��������������������һ�ѡ�\n");
			tell_object(me,"\n$HIC�����龰����ң�Ӳ�Ȼ��ŭ�����ݺ�˦�������һ�Ƕ��⣬תͷ��Ȼ��ȥ��\n");
			me->add("xy/��ɶ�",1);
			me->set("xy/renwu7_33",1);//��ң�Ⱦ��º�����:��ң�Ӹ�����ȥ
		}
	}
}

XiaoYao_END;

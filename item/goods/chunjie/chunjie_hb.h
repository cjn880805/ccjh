//chunjie_hb.h ѹ����
//muri 2002-2-5

ITEM_BEGIN(CIchunjie_hb)

void create(int nFlag = 0)	
{
	set_name("ѹ����", "hong bao");
	set_weight(10);
    set("no_give", "�ô󷽵���ѽ��������Ұɣ�");
    set("value", 0l);
	set("no_steal", 1);
	set("no_beg", 1);
    set("no_put", 1);
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���");

	set("long", "���ǽ�������˾���͸�������������ʱ����Ȼ���߷ܶ��������ǵ�ѹ������");
	set("unit", "��");	

	set("open_msg", "С�������˺���˺�����");
}

int Can_Use()
{
	return 1;
}
 
int do_use(CChar * me, CContainer * who)
{
	if(querystr("owner")[0])
	{
		char msg[255];
		int number;
		if(!query("number"))
		{
			if(random(2))
			{
				number=random(1001)+1000;
				if(me->query("level")>10)
				{
					message_vision(snprintf(msg, 255, "\n$HIY$N%s���Ӻ���е�����һ�ѵĽ�ң������̵���������...", querystr("open_msg")), me);
					tell_object(me,snprintf(msg, 255, "1����ҡ�2����ҡ�3����ҡ�4�����......") );
					tell_object(me,snprintf(msg, 255, "108����ҡ�208����ҡ�308����ҡ�408�����......"));
					tell_object(me,snprintf(msg, 255, "%d����ҡ�%d����ҡ�%d����ҡ�%d�����......",number-500-random(100),number-300-random(100),number-100-random(100),number));
					tell_object(me,snprintf(msg, 255, "$HIY��������������ǰ����ѽ�ң�����ĵ��˵�ͷ���ܹ��յ���%d����ҵ�һ�������\n",number));
				}
				else
				{
					number=1;
					message_vision(snprintf(msg, 255, "\n$HIY$N%s���Ӻ���е�����һ�ѵĽ�ң������̵���������...", querystr("open_msg")), me);
					tell_object(me,snprintf(msg, 255, "1����ҡ�1����ҡ�1����ҡ�����ֻ��1����ҡ���") );
					tell_object(me,snprintf(msg, 255, "$HIY��ɵ�ɵɵĿ������ֻ����1ö��ҵĺ��������һ��п�����������ã�\n",number));
				}
				CMoney::Pay_Player(me, number);
			}
			else
			{
				if(me->query("level")>10)
					number=random(61)+60;
				else
					number=1;
				me->add("combat_exp",number);
				me->UpdateMe();
				tell_object(me,snprintf(msg, 255, "\n$HIY��%s���������澹��һ���������߽����ľ���֮��ȫ�������������%d��Ľ������顣\n", querystr("open_msg"),number));
			}
		}
		else
		{
			if(me->query("level")>10)
				number=(random(101)+60)*query("number");
			else
				number=1;
			me->add("combat_exp",number);
			me->UpdateMe();
			message_vision(snprintf(msg, 255, "\n$HIY$N%s���������澹��һ���������߽����ľ���֮��ȫ��$N�Ķ�֮�󣬴���������%d��Ľ������顣\n", querystr("open_msg"),number), me);
		}
	}
	destruct(this);
	return 1;

}

void owner_is_killed(CChar * me)
{
	destruct(this);
}

ITEM_END;





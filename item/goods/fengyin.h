//�Ϲŷ�ӡ
//fengyin.h
//2001-02-09

AUTOCOMBINE_BEGIN(CIfengyin);

virtual void create(int nFlag = 0)		
{
	set_name("��ӡħ��", "fengyin");

	set("base_value", 150);
	set("base_weight", 1500);

	set_amount(1);
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	char str[255];
	string msg;

	if(! target || ! target->Query(IS_BOX))
		return notify_fail("��ӡħ��ֻ�ܶ�����ʹ�ã�");

	if(me->query("mp") < 100)
		return notify_fail("��ķ������㡣");

	me->add("mp", -100);

	if(EQUALSTR(target->querystr("status"), "locked"))
	{
		msg = snprintf(str, 255, "$N���˸���ָ�����жϺ�һ����%s�����ˣ�", query_self_rude(me));

		//����
		if(EQUALSTR(target->querystr("owner"), me->querystr("id")))
		{
			//���Լ��ϵ�����һ���Ӿ��ܽ⿪��
			msg += "ֻ������һ��$n���ˡ�";
			((CBox *)target)->UnLocked();
		}
		else
		{
			//�����Լ��ϵ�����������Ҫ��Щ������
			if( ! ((CBox *)target)->UnLocked(6 * me->query("level")) )
			{
				msg += "ֻ������һ��$n���ˡ�";
			}
			else
			{
				msg += "���$n��˿������";
			}
		}
	}
	else
	{
		//����
		msg = "$N���˸���ָ����������������������ۣ�����ֻ��ž��һ����Ʈ���ŷ���������$n��";
		snprintf(str, 60, "%s�ķ�ӡ", me->name());
		
		((CBox *)target)->Locked(str, 30 + 30 * me->query("level"), me);		//���� ÿ������60���;ö�
	}

	message_vision(msg.c_str(), me, target);
	destruct(this);

	return 1; 
}

AUTOCOMBINE_END;

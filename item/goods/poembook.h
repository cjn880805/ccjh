ITEM_BEGIN(CIpoembook)

virtual void create(int nFlag = 0)		
{
	set_name("��ʫѡ��", "poembook");
    set_weight(500);
    set("unit", "��");
    set("material", "paper");
	set("is_poem",1);
	set("no_give",1);
	set("no_drop",1);
	set("no_get",1);
	call_out(selfdest, random(300) + 1);
};


static void selfdest(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * me = ob->environment();

	if(userp(me))
		tell_object((CChar *)me, "ͻȻһ��紵������ʫѡ���ڷ��л�Ϊ�����ֽ����������˳���ȥ�ˡ�");
	else
		tell_room(me, "ͻȻһ��紵������ʫѡ���ڷ��л�Ϊ�����ֽ����������˳���ȥ�ˡ�");

	destruct(ob);
	return;
}



ITEM_END;


// wuzheng_xinfa.h �����ķ�
//code by Fisho
//date : 2000-12-07

FORCE_BEGIN(CSwuzheng_xinfa);

virtual void create()
{
	set_name( "�����ķ�");
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force")  ;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_skill("force", 1) > 9)
		return 1;
	return notify_fail("��Ļ����ڹ�����Ҫ��һ����ߡ�");
	
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("�����ķ�ֻ������̵������������ȡ�");
}
/**************
return SKILL_D("wuzheng-xinfa/") + func;

  //perform 
  virtual int Cast(string magic, CChar * me, CContainer *  ob = NULL)
  {
  string msg;
  CChar * target= NULL;
  
	if (ob && ob->Query(IS_CHAR))
	target=(CChar *) ob;
	
	  if (magic=="fugu")
	  {
	  
		}
		}
*************/
FORCE_END;

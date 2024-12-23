
// wuzheng_xinfa.h 无争心法
//code by Fisho
//date : 2000-12-07

FORCE_BEGIN(CSwuzheng_xinfa);

virtual void create()
{
	set_name( "无争心法");
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force")  ;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_skill("force", 1) > 9)
		return 1;
	return notify_fail("你的基本内功还需要进一步提高。");
	
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("无争心法只能用请教的来增加熟练度。");
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
